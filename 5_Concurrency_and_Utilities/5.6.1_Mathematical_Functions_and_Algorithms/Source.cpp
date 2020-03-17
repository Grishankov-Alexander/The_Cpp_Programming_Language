#include <numeric>  // numerical algorithms
#include <cmath>  // sqrt, log, sin
#include <complex>  // complex version of cmath
#include <list>
#include <iostream>
using namespace std;


void f()
{
	list<double> lst{ 1, 2, 3, 4, 5, 9999.99999 };
	// calculate the sum
	auto s = accumulate(lst.begin(), lst.end(), 0.0);
	cout << s << "\n";  // print 10014.9999
}