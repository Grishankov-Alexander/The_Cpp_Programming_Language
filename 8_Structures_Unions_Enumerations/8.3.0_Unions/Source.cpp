#include <iostream>
using namespace std;


enum Type { str, num };
struct Entry {
	char* name;
	Type t;
	char* s;  // use s if t==str
	int i;  // use i if t==num
};
void f(Entry* p)
{
	if (p->t == str)
		cout << p->s;
}

union Value {
	char* s;
	int i;
};
struct Entry {
	char* name;
	Type t;
	Value v;  // use v.s if t==str; use v.i if t==num
};
void f(Entry* p)
{
	if (p->t == str)
		cout << p->v.s;
	// ...
}

union Fudge {
	int i;
	int* p;
};
int* cheat(int i)
{
	Fudge a;
	a.i = i;
	return a.p;  // bad use
}
int* cheat2(int i)
{
	return reinterpret_cast<int*>(i);  // obviously ugly and dangerous
}