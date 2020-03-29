#include <vector>
using namespace std;


void f(vector<int>& v)
{
	bool sensitive = true;
	sort(v.begin(), v.end(),
		[](int x, int y) { return sensitive ? x < y : abs(x) < abs(y); });  // error: can't access sensitive
	sort(v.begin(), v.end(),
		[sensitive](int x, int y) { return sensitive ? x < y : abs(x) < abs(y); });
}

template<typename... Var>
void algo(int s, Var... v)
{
	auto helper = [&s, &v...]{ return s * (h1(v...) + h2(v...)); };
}