#include <vector>
#include <string>
#include <initializer_list>
#include <numeric_limits>
using namespace std;


int f(double d, Matrix& m)
{
	int v{ 7 };  // direct initialization
	int v2 = { 7 };  // copy initialization
	int v3 = m[{ 2, 3 }];  // assume m takes value pairs as subscripts
	v = { 8 };  // right-hand operand of assignment
	{v} = 9;  // error: not left-hand operand of assignment
	f({ 10.0 });  // function argument
	return { 1 };  //return value
}

int high_value(initializer_list<int> val)
{
	int high = numeric_limits<int>::lowest();
	if (!val.size()) return high;
	for (auto x : val)
		if (x > high) high = x;
	return high;
}
int v1 = high_value({ 1, 2, 3, 4, 5, 6, 7 });
int v2 = high_value({ -1, 2, v1, -9, 20 });

auto x0 = {};  // error (no element type)
auto x1 = { 1 };  // initializer_list<int>
auto x2 = { 1, 2.2 };  // error: nonhomogeneous lis

template<typename T>
void f(T);
f({ 1 });  // error: an unqualified list does not match "plain T"

template<class T>
void f2(const vector<T>&);
f2({ 1, 2, 3 });  // error: cannot deduce T