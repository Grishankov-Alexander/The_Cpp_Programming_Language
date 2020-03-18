#include <string>
#include <vector>
#include <list>
#include <iostream>
using namespace std;


int x;  // global x
void f()
{
	int x;  // local x hides global x
	x = 1;  // assign to local x
	{
		int x;  // hides first local x
		x = 2;  // assign to second local x
	}
	x = 3;  // assign to first local x
}
int* p = &x;  // take address of global x

void f2()
{
	int x = 1;  // hide global x
	::x = 2;  // assign to global x
	x = 2;  // assign to local x
}

void f3()
{
	int x = x;  // perverse: initialize x with its own (uninitialized) value
}

void f4()  // perverse: use of two different objects both called x in a single scope
{
	int y = x;  // use globalx: y = 2
	int x = 22;
	y = x;  // y=22
}

void f5(int x)
{
	int x;  // error
}

void f6(vector<string>& v, list<int>& lst)
{
	for (const auto& x : v) cout << x << '\n';
	for (auto x : lst) cout << x << '\n';
	for (int i = 0; i != v.size(); ++i) cout << v[i] << '\n';
	for (auto i : { 1, 2, 3, 4, 5, 6, 7 }) cout << i << '\n';
}