#include <climits>
#include <limits>
#include <stdexcept>
using namespace std;


// 10.5.2 Conversions
namespace Conversions {
	void f(double d)
	{
		char c = d;  // beware: double-precision float to char conversion
	}
	void f(double d)
	{
		char c{ d };  // error: double to char
	}
}


// 10.5.2.1 Integreal Conversions
namespace integral_conversions {
	unsigned char uc = 1023;  // binary 1111111111: uc becomes binary 11111111, that is 255
	signed char sc = 1023;  // implementation-defined (127 or -1)
}


// 10.5.2.2 Floating-Point Conversions
namespace float_conversions {
	float f = FLT_MAX;  // largest float value
	double d = f;  // OK: d == f

	double d2 = DBL_MAX;  // largest double value
	float f2 = d2;  // undefined if FLT_MAX < DBL_MAX

	long double ld = d2;  // OK
	long double ld2 = numeric_limits<long double>::max();
	double d3 = ld2;  // undefined if sizeof(long double) > sizeof(double)
}


// 10.5.2.5 Boolean Conversions
namespace boolean_conversions {
	void f(int* p, int i)
	{
		bool is_not_zero = p;  // true if p != 0
		bool b2 = i;  // true if i != 0
	}

	void fi(int);
	void fb(bool);
	void ff(int* p, int* q)
	{
		if (p) do_something(*p);  // OK
		if (q != nullptr) do_something(*q);  // OK, verbose
		fi(p);  // error: no pointer to int conversion
		fb(p);  // OK: pointer to bool conversion
	}
}


// 10.5.2.6 Floating-Integral Conversions
namespace float_int_conversions {
	int i = 2.7;  //  i becomes 2
	char b = 2000.7;  // undefined for 8-bit chars
	int i = float(1234567890);
	
	char checked_cast(int i)
	{
		char c = i;  // warning: not portable
		if (i != c) throw std::runtime_error{ "int-to-char check failed" };
		return c;
	}
	void my_code(int i)
	{
		char c = checked_cast(i);
	}
}