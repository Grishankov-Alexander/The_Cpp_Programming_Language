#include <memory>
#include <iterator>
#include <algorithm>
using namespace std;


// 13.6.1 A simple vector
namespace simple_vector {
	template<class T, class A = allocator<T>>
	class vector {
	private:
		T* elem;  // start of allocation
		T* space;  // end of element sequence, start of space allocated for possible expansion
		T* last;  // end of allocated space
		A alloc;  // allocator
	public:
		using size_type = unsigned int;  // type used for vector sizes

		explicit vector(size_type n, const T& val = T(), const A & = A());
		vector(const vector& a);  // copy constructor
		vector& operator=(const vector& a);  // copy assignment
		vector(vector&& a);  // move constructor
		vector& operator=(vector&& a);  // move assignment
		~vector();

		size_type size() const { return space - elem; }
		size_type capacity() const { return last - elem; }
		void reserve(size_type n);  // increase capacity to n
		void resize(size_type n, const T & = {});  // increase size to n
		void push_back(const T&);  // add an element at the end
	};

	template<class T, class A>
	vector<T, A>::vector(size_type n, const T& val, const A& a)  // elaborate implementation
		: alloc{ a }  // copy the allocator
	{
		elem = alloc.allocate(n);  // get memory for elements
		iterator p;
		try {
			iterator end = elem + n;
			for (p = elem; p != end; ++p)
				alloc.construct(p, val);  // construct element
			last = space = p;
		}
		catch (...) {
			for (iterator q = elem; q != p; ++q)
				alloc.destroy(q);  // destroy constructed elements
			alloc.deallocate(elem, n);  // free memory
			throw;  // rethrow
		}
	}

	template<class For, class T>
	void uninitialized_fill(For beg, For end, const T& x)
	{
		For p;
		try {
			for (p = beg; p != end; ++p)
				::new(static_cast<void*>(&*p)) T(x);  // construct copy of x in *p
		}
		catch (...) {
			for (For q = beg; q != p; ++q)
				(&*q)->~T();  // destroy element
			throw;  // rethrow
		}
	}

	template<class T, class A>
	vector<T, A>::vector(size_type n, const T& val, const A& a)
		: alloc{ a }
	{
		elem = alloc.allocate(n);
		try {
			uninitialized_fill(elem, elem + n, val);  // copy elements
			space = last = elem + n;
		}
		catch (...) {
			alloc.deallocate(elem, n);
			throw;
		}
	}
}



// 13.6.2 Representing memory Explicitly
namespace repr_mem_explicit {
	template<class T, class A = allocator<T>>
	struct vector_base {
		A alloc;  // allocator
		T* elem;  // start of allocation
		T* space;  // start of expansion space
		T* last;  // end of allocated space

		vector_base(const A& a, typename A::size_type n)
			: alloc{ a }, elem{ alloc.allocate(n) }, space{ elem + n }, last{ elem + n } {}
		vector_base(const vector_base&) = delete;  // no copy operations
		vector_base& operator=(const vector_base&) = delete;
		vector_base(vector_base&&);  // move operations
		vector_base& operator=(vector_base&&);
		~vector_base() { alloc.deallocate(elem, last - elem); }
	};

	template<class T, class A>
	vector_base<T, A>::vector_base(vector_base&& a)
		: alloc{ a.alloc },
		elem{ a.elem },
		space{ a.space },
		last{ a.space }
	{
		a.elem = a.space = a.last = nullptr;  // no longer owns any memory
	}

	template<class T, class A>
	vector_base<T, A>& vector_base<T, A>::operator=(vector_base&& a)
	{
		swap(*this, a);
		return *this;
	}

	template<class T, class A = allocator<T>>
	class vector {
		vector_base<T, A> vb;  // the data is here
		void destroy_elements();
	public:
		using size_type = unsigned int;
		explicit vector(size_type n, const T& val = T(), const A & = A());
		vector(const vector& a);  // copy constructor
		vector& operator=(const vector& a);  // copy assignment
		vector(vector&& a);
		vector& operator=(vector&& a);
		~vector() { destroy_elements(); }

		size_type size() const { return vb.space - vb.elem; }
		size_type capacity() const { return vb.last - vb.elem; }
		void reserve(size_type);  // increase capacity
		void resize(size_type, const T& = {});  // change the number of elements
		void clear() { resize(0); }  // make the vector empty
		void push_back(const T&);  // add an element at the end
	};

	template<class T, class A>
	void vector<T, A>::destroy_elements()
	{
		for (T* p = vb.elem; p != vb.space; ++p)
			p->~T();  // destroy element
		vb.space = vb.elem;
	}

	template<class T, class A>
	vector<T, A>::vector(size_type n, const T& val, const A& a)
		: vb{ a, n }  // allocate space for n elements
	{
		uninitialized_fill(vb.elem, vb.elem + n, val);  // make n copies of val
	}

	template<class T, class A>
	vector<T, A>::vector(const vector& a)
		: vb{ a.alloc, a.size() }
	{
		uninitialized_copy(a.begin(), a.end(), vb.elem);
	}

	template<class T, class A>
	vector<T, A>& vector<T, A>::operator=(vector&& a)  // move assignment
	{
		clear();  // destroy elements
		swap(*this, a);  // transfer ownership
		return *this;
	}

	template<class T, class A>
	vector<T, A>::vector(vector&& a)  // move constructor
		: vb{ move(a.vb) } {}  // transfer ownership


	// 13.6.3 Assignment
	template<class T, class A>
	vector<T, A>& vector<T, A>::operator=(const vector& a)  // offers the strong guarantee
	{
		vector_base<T, A> b(a.vb.alloc, a.size());  // get memory
		uninitialized_copy(a.begin(), a.end(), b.elem);  // copy elements
		destroy_elements();
		swap(vb, b);  // transfer ownership
		return *this;
	}

	template<class T, class A>
	vector<T, A>& vector<T, A>::operator=(const vector& a)
	{
		vector temp{ a };  // copy allocator
		swap(*this, temp);
		return *this;
	}

	template<class T, class A>
	vector<T, A>& vector<T, A>::operator=(const vector& a)
	{
		if (capacity() < a.size()) {  // allocate new vector representation
			vector temp{ a };
			swap(*this, temp);  // swap representations
			return *this;
		}
		if (this == &a) return *this;
		size_type sz = size();
		size_type asz = a.size();
		vb.alloc = a.vb.alloc;
		if (asz <= sz) {
			copy(a.begin(), a.begin() + asz, vb.elem);
			for (T* p = vb.elem + asz, p != vb.space; ++p)  // destroy surplus elements
				p->~T();
		}
		else {
			copy(a.begin(), a.begin() + sz; vb.elem);
			uninitialized_copy(a.begin() + sz, a.end(), vb.space);  // construct extra elements
		}
		vb.space = vb.elem + asz;
		return *this;
	}

	template<class T, class A>
	void safe_assing(vector<T, A>& a, const vector<T, A>& b)
	{
		vector<T, A> temp{ b };
		swap(a, temp);
	}
	template<class T, class A>
	void safe_assign(vector<T, A>& a, vector<T, A> b)
	{
		swap(a, b);
	}


	// 13.6.4 Changing size
	template<typename In, typename Out>
	Out uninitialized_move(In b, In e, Out oo)
	{
		for (; b != e; ++b, ++oo)
		{
			new(static_cast<void*>(&*oo)) T { move(*b) };
			b->~T();
		}
		return b;
	}

	template<class T, class A>
	void vector<T, A>::reserve(size_type newalloc)
	{
		if (newalloc <= capacity()) return;
		vector<T, A> v(newalloc);
		copy(elem, elem + size(), v.begin());
		swap(*this, v);
	}

	template<class T, class A>
	void vector<T, A>::reserve(size_type newalloc)
	{
		if (newalloc <= capacity()) return;
		vector_base<T, A> b{ vb.alloc, newalloc };
		uninitialized_move(vb.elem, vb.elem + size(), b.elem);
		swap(vb, b);
	}

	template<typename In>
	void destroy(In b, In e)
	{
		for (; b != e; ++b) b->~T();
	}

	template<class T, class A>
	void vector<T, A>::resize(size_type newsize, const T& val)
	{
		reserve(newsize);
		if (newsize > size())
			uninitialized_fill(vb.elem + size(); vb.elem + newsize; val);
		else
			destroy(vb.elem + newsize, vb.elem + size());
		vb.space = vb.last = vb.elem + newsize;
	}

	template<class T, class A>
	void vector<T, A>::push_back(const T& x)
	{
		if (capacity() == size())
			reserve(sz ? sz * 2 : 8);  // grow or start with 8
		vb.alloc.construct(&vb.elem[size()], val);  // add val at end
		++vb.space;  // increment size
	}
}
