#include <iostream>
using namespace std;


// 2.4 Modularity
namespace modularity
{
	// Declarations:
	double sqrt(double);  // the square root function takes a double and returns a double
	class Vector {
	public:
		Vector(int s);
		double& operator[](int i);
		int size();
	private:
		double* elem;  // elem points to an array of sz doubles
		int sz;
	};
	// Definitions
	double sqrt(double d)
	{
		// ... algorithm
	}
	Vector::Vector(int s)  // constructor
		:elem{ new double[s] }, sz{ s } {}  // initialize members
	double& Vector::operator[](int i)  // subscripting
	{
		return elem[i];
	}
	int Vector::size() { return sz; }
}


// 2.4.2 Namespaces
namespace My_code {
	class complex {/*...*/};
	complex sqrt(complex);
	int main();
}

int My_code::main()
{
	complex z{ 1, 2 };
	auto z2 = sqrt(z);
	cout << "{" << z2.real() << "," << z2.imag() << "}\n";
}

int main()
{
	return My_code::main();
}


// 2.4.3 Error Handling
// 2.4.3.1 Exceptions
namespace exceptions {
	double& Vector::operator[](int i)
	{
		if (i < 0 || size() <= i) throw out_of_range{ "Vector::operator[]" };
		return elem[i];
	}

	void f(Vector& v)
	{
		// ...
		try {  // exceptions here are handled by the handler defined below
			v[v.size()] = 7;
		}
		catch (out_of_range) {  // out_of_range error
			// ... handle range error ...
		}
	}
}


// 2.4.3.2 Invariants
namespace invariants {
	Vector::Vector(int s)
	{
		if (s < 0) throw std::length_error{"Message"};
		elem = new double[s];
		sz = s;
	}

	void test()
	{
		try {
			Vector v(-27);
		}
		catch (std::length_error) { /*Handle negative size*/ }
		catch (std::bad_alloc) { /* Handle memory exhaustion */ }
	}
}


// 2.4.3.3 Static Assertions
namespace static_assertions {
	// check integer size at compile time
	static_assert(4 <= sizeof(int), "integers are too small");
	constexpr double C = 299792.458;  // light speed in km/s
	void f(double speed)
	{
		constexpr double local_max = 160.0 / (60 * 60);
		// error: speed must be a constant
		static_assert(speed < C, "can't go that fast");
		static_assert(local_max < C, "Can't go that fast");
	}
}