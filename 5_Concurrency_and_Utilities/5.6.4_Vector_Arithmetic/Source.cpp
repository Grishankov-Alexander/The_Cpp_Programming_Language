#include <valarray>
using namespace std;


void f(valarray<double>& a1, valarray<double>& a2)
{
	valarray<double> a = a1 * 3.14 + a2 / a1;  // numeric array operators *, +, /, and =
	a2 += a1 * 3.14;
	a = abs(a);
	double d = a2[7];
}