#include <string>
#include <algorithm>


// 23.4.1 Data members
template<typename T>
struct X {
	int m1 = 7;
	T m2;
	X(const T& x) : m2{ x } {}
};
X<int> xi{ 9 };
X<std::string> xs{ "Rapperswil" };


// 23.4.2 Member Functions
template<typename T>
struct X {
	void mf1() {}  // defined in-class
	void mf2();
};

template<typename T>
void X<T>::mf2() {};  // defined out of class


// 23.4.3 Member Type Aliases
template<typename T>
class Vector {
public:
	using value_type = T;
	using iterator = Vector_iter<T>;  // defined elsewhere
};


// 23.4.4 static Members
template<typename T>
struct X {
	static constexpr Point p{ 100, 250 };  // Point must be a literal type
	static const int m1 = 7;
	static int m2 = 8;  // error: not const
	static int m3;
	static void f1() {}
	static void f2();
};

template<typename T>
int X<T>::m1 = 88;  // error: two initializers
template<typename T> int X<T>::m3 = 99;

template <typename T>
void X<T>::f2() {}

template<typename T>
struct X {
	static int a;
	static int b;
};
int* p = &X<int>::a;


// 23.4.5 Member Types
template<typename T>
struct Y {
	enum E1 { a, b };
	enum E2;
	enum class E3;
	enum E4 : char;

	struct C1 {};
	struct C2;
};

template<typename T>
enum class Y<T>::E3 { a, b };

template<typename T>
enum Y<T>::E4 : char { xx, yy };

template<typename T>
struct Y<T>::C2 {};


 
// 23.4.6 Member Templates
namespace member_templates {
	template<typename Scalar>
	class complex {
		Scalar re, im;
	public:
		complex() : re{}, im{} {}
		template<typename T>
		complex(T real, T imag = T{})
			: re{ real }, im{ imag } {}

		complex(const complex&) = default;  // copy constructor
		template<typename T>
		complex(const complex<T>& c) : re{ c.real() }, im{ c.imag() } {}

		Scalar real() const { return re; }
		Scalar imag() const { return im; }
	};

	complex<float> cf;  // default value
	complex<double> cd{ cf };  // OK: uses float to double conversion
	complex<double> cd2{ 2.0F };  // OK: float to double conversion

	complex<float> cf2{ 2.0, 3.0 };  // error: no implicit double->float
	complex<float> cf3{ cd };  // error: no implicit double->float conversion

	class Quad {};  // no conversion to int
	complex<Quad> cq;
	complex<int> ci{ cq };  // error: no Quad to int conversion
}


// 23.4.6.3 Use of Nesting
namespace use_of_nesting {
	template<typename T, typename Allocator>
	class List;
	
	template<typename T>
	class Link {
	private:
		T val;
		Link* suc;
		Link* pre;

		template<typename U, typename A>
		friend class List;
	};

	template<typename T>
	struct Iterator {
	private:
		Link<T>* current_position;
	};

	template<typename T, typename Alloc>
	class List {
	public:
		Iterator<T> begin();
		Iterator<T> end();
	};

	void fct(Iterator<int> b, Iterator<int> e)
	{
		auto p = std::find(b, e, 17);
	}

	void user(List<int, My_allocator>& lm, List<int, Your_allocator>& ly)
	{
		fct(lm.begin(), lm.end());
		fct(ly.begin(), ly.end());
	}
}


// 23.4.7 Friends
namespace friends {
	template<typename T>
	class Vector {
		T v[4];
	public:
		friend Vector operator*<>(const Matrix<T>&, const Vector&);
	};

	template<typename T>
	class Matrix {
		Vector<T> v[4];
	public:
		friend Vector<T> operator*<>(const Matrix&, const Vector<T>&);
	};

	template<typename T>
	Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
	{
		Vector<T> r;
		// use m.v[i] and v.v[i] for direct access to elements
		return r;
	}

	class C;
	using C2 = C;
	template<typename T>
	class My_class {
		friend C;  // OK
		friend C2;  // OK
		friend class C3;  // OK: introduces a new class C3
	};
	template<typename T>
	class my_other_class {
		friend T;  // my argument is my friend
		friend class T;  // error: redundant class
		friend My_class<T>;  // My class with the corresponding argument is my friend
	};

	template<typename T, typename A>
	class List;
	template<typename T>
	class Link {
		template<typename U, typename A>
		friend class List;
	};
}
