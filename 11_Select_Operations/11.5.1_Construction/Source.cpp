#include <limits>
#include <cmath>
using namespace std;


auto d1 = double{ 2 };  // d1 == 2.0
double d2{ double{ 2 } / 4 };  // 0.5

void f(int);
void f(double);
void g(int i, double d)
{
	f(i);
	f(double{ i });  // error: int to float conversion
	f(d);
	f(int{ d });  // error: {} doesn't truncate
	f(static_cast<int>(d));  // truncates
	f(round(d));  // rounded value
	// call f(int) with a rounded value. if the d is overflows the int, this still truncates
	f(static_cast<int>(lround(d)));
}

static_assert(sizeof(int) == sizeof(double), "unexpected sizes");
constexpr int x = numeric_limits<int>::max();  // largest possible int
constexpr double d = x;
constexpr int y = d;
constexpr bool b = y == x;
double d{ 1234 };  // fine

void g2(char* p)
{
	int x = int{ p };  // no char* to int conversion
	using Pint = int*;
	int* p2 = Pint{ p };  // no char* to int* conversion
}

template<class T> void f(const T&);
void g3()
{
	f(int{});  // default int value
	f(complex<double>{});  // default complex value
}