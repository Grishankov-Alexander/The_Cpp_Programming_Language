#include <vector>
using namespace std;


int sum(vector<int>& v)
{
	int s = 0;
	for (int x : v)
		s += x;
	return s;
}

int sum2(vector<int>& v)
{
	int s = 0;
	for (auto p = begin(v); p != end(v); ++p)
		s += *p;
	return s;
}

void incr(vector<int>& v)
{
	for (int& x : v) ++x;
}

template <class T> T accum(vector<T>& v)
{
	T sum{};
	for (const T& x : v) sum += x;
	return sum;
}