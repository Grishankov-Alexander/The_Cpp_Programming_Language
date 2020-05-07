#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


void g(int);

template<typename T>
void f(T a)
{
	g(a);  // g is bound at a point of instantiation
	if (i) h(a - 1);  // h is bound at a point of instantiation
}

void h(int i)
{
	extern void g(double);
	f(i);
}
// point of declaration for f<int>

template<typename T>
class Container {
	vector<T> v;
public:
	void sort();
};

// point of instantiation of Container<T>
void f()
{
	Container<int> c;  // point of use
	c.sort();
}

void fff()
{
	struct S {};
	Container<S> cs;
}

template<typename T, typename S>
void print_sorted(vector<T>& v, S* sort, ostream& os)
{
	(*sort)(v.begin(), v.end());
	for (const auto& x : v)
		os << x << '\n';
}

void fct(vector<string>& vec)
{
	using Iter = decltype(vec.begin());
	print_sorted(vec, &sort<Iter>, cout);
}

int main()
{
	vector<string> v{ "abc", "defg", "hijklmnop" };
	fct(v);
}