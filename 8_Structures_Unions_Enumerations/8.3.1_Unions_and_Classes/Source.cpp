#include <complex>
#include <string>
using namespace std;


union U {
	int m1;
	complex<double> m2;  // complex has a constructor
	string m3;  // string has a constructor (maintaining a serious invariant)
};

void f2(U x)
{
	U u;  // error: which default constructor?
	U u2 = x;  // error: which copy constructor ?
	u.m1 = 1;  // assign to int member
	string s = u.m3;  // disaster: read from string member
	return;  // error: which destructors are called for x, u and u2 ?
}

union U2 {
	int a;
	const char* p{ "" };
};
U2 x1;  // default initialized to x1.p == ""
U2 x2{ 7 };  // x2.a == 7