#include <vector>
#include <complex>
#include <list>

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
	for (auto x : c)
		v += x;
	return v;
}

void user(std::vector<int>& vi, std::list<double>& ld, std::vector<std::complex<double>>& vc)
{
	int x = sum(vi, 0);  // the sum of a vector of ints (add ints)
	double d = sum(vi, 0.0);  // the sum of a vector of ints (add doubles)
	double dd = sum(ld, 0.0);  // the sum of a list of doubles
	auto z = sum(vc, std::complex<double>{});  // the sum of a vector of complex<double>
											   // the initial value is { 0.0, 0.0 }
}
