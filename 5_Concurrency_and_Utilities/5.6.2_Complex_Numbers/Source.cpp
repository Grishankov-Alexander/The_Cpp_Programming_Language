#include <complex>
using namespace std;


void f(complex<float> fl, complex<double> db)
{
	complex<long double> ld{ fl + sqrt(db) };
	db += fl * 3;
	fl = pow(1 / fl, 2);
}
