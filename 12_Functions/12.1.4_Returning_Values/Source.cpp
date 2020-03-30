#include <string>
#include <vector>
using namespace std;


string to_string(int a);  // prefix return type
auto to_string(int a)->string;  // suffix return type
template<class T, class U>
auto product(const vector<T>& x, const vector<U>& y) -> decltype(x* y);

int fac(int n)
{
	return (n > 1) ? n * fac(n - 1) : 1;
}
int fac2(int n)
{
	if (n > 1) return n * fac2(n - 1);
	return 1;
}

int* fp()
{
	int local = 1;
	return &local;  // bad
}
int& fr()
{
	int local = 1;
	return local;  // bad
}