


template<typename T>
class Ptr {
	T* ptr;
	T* array;
	int sz;
public:
	template<int N>
	Ptr(T* p, T(&a)[N]);  // bind to array a, sz==N, initial value p
	Ptr(T* p, T* a, int s);  // bind to array a of size s, initial value p
	Ptr(T* p);  // bind to single object, sz==0, initial value p

	Ptr& operator++();  // prefix
	Ptr operator++(int);  // postfix
	Ptr& operator--();  // prefix
	Ptr operator--(int);
	T& operator*();  // prefix
};

template<typename T>
Ptr<T>& Ptr<T>::operator++()  // return current object after incrementing
{
	// ... check that ptr+1 can be pointed to
	return *++ptr;
}
template<typename T>
Ptr<T> Ptr<T>::operator++(int)  // increment and return a Ptr with the old value
{
	// ... check that ptr+1 is legit
	Ptr<T> old{ ptr, array, sz };
	++ptr;
	return old;
}

void f2(Ptr<int> a)  // checked
{
	int v[200]{};
	Ptr<int> p(v, v);
	p--;
	*p = *a;  // runtime error: p out of range
	++p;
	*p = *a;  // OK
}

void f3(T a)
{
	T v[200];
	Ptr<T> p(v, v, 200);
	p.operator--(0);  // suffix: p--
	p.operator*() = a;  // run-time error: p out of range
	p.operator++();  // prefix: ++p
	p.operator*() = a;  // OK
}