#include <initializer_list>
#include <istream>


// 3.2.1.1 An arithmetic Type
namespace arithmetic_type {
	
	class complex {
		double re, im;  // representation: two doubles
	public:
		complex(double r, double i) : re{ r }, im{ i } {}  // construct complex from two scalars
		complex(double r) : re{ r }, im{ 0 } {}  // construct complex from one scalar
		complex() : re{ 0 }, im{ 0 } {}  // default complex: {0,0}

		double real() const { return re; }  // will not modify object
		void real(double d) { re = d; }
		double imag() const { return im; }
		void imag(double d) { im = d; }

		// add to re and im and return itself
		complex& operator+=(complex z) { re += z.re; im += z.im; return *this; }
		complex& operator-=(complex z) { re -= z.re; im -= z.im; return *this; }

		complex& operator*=(complex);  // defined out-of-class somewhere
		complex& operator/=(complex);
	};
	
	complex operator+(complex a, complex b) { return a += b; }
	complex operator-(complex a, complex b) { return a -= b; }
	complex operator-(complex a) { return { -a.real(), -a.imag() }; }
	complex operator*(complex a, complex b) { return a *= b; }
	complex operator/(complex a, complex b) { return a /= b; }

	bool operator==(complex a, complex b)
	{
		return a.real() == b.real() && a.imag() == b.imag();
	}
	bool operator !=(complex a, complex b) { return !(a == b); }
	complex sqrt(complex);

	// class complex can be used like this:
	void f(complex z)
	{
		complex a{ 2.3 };
		complex b{ 1 / a };
		complex c{ a + z * complex{ 1, 2.3 } };
		// ...
		if (c != b)
			c = -(b / a) + 2 * b;
	}
}


// 3.2.1.2 A Container
namespace container {
	class Vector {
	private:
		double* elem;
		int sz;
	public:
		Vector(int s) : elem{ new double[s] }, sz{ s }  // constructor: acquire resources
		{
			for (int i = 0; i != s; ++i) elem[i] = 0;  // initialize elements
		}
		~Vector() { delete[] elem; }  // destructor: release resources
		double& operator[](int i);
		int size() const;
	};

	void fct(int n)
	{
		Vector v{ n };
		// ... use v ...
		{
			Vector v2{ 2 * n };
			//... use v && v2 ...
		}  // v2 is destroyed here
	}  // v is destroyed here
}


// 3.2.1.3 Initializing Containers
namespace initializing_containers {
	class Vector {
		double* elem;
		int sz;
	public:
		Vector(std::initializer_list<double>);  // initialize with a list
		void push_back(double);  // add element at end increasing the size by one
	};

	Vector::Vector(std::initializer_list<double> lst)
		: elem{ new double[lst.size()] }, sz{ lst.size() }
	{
		std::copy(lst.begin(), lst.end(), elem);  // copy from lst into elem
	}

	Vector v1 = { 1, 2, 3, 4, 5 };
	Vector v2{ 1.23, 3.45, 6.7, 8 };

	Vector read(std::istream is)
	{
		Vector v;
		for (double d; is >> d;)  // read doubles into d
			v.push_back(d);
		return v;
	}
}