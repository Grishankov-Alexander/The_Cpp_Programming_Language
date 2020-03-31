#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void error(string) { /*...*/ }
void (*efct)(string);  // pointer to function void(string)
void f()
{
	efct = &error;  // efct points to error
	efct("Message");  // call error through efct
}

void (*f1)(string) = &error;  // OK: same as = error
void (*f2)(string) = error;  // OK: same as = &error
void g()
{
	f1("Vasa");  // OK: same as (*f1)("Vasa")
	(*f1)("Mary Rose");  // OK: same as f1("Mary Rose")
}

void g2()
{
	void (*pf)(string);  // pointer to void(string)
	void f1(string);  // void(string)
	int f2(string);  // int(string)
	void f3(int*);  // void(int*)

	pf = &f2;  // error: bad return type
	pf = &f3;  // error: bad argument type
	pf = &f1;  // OK
	pf("Hera");  // OK
	pf(1);  // error: bad argument type
	int i = (*pf)("Zeus");  // error: void assigned to int
}

using P1 = int(*)(int*);
using P2 = void(*)(void);
void f(P1 pf)
{
	P2 pf2 = reinterpret_cast<P2>(pf);
	pf2();  // likely serious problem
	P1 pf1 = reinterpret_cast<P1>(pf2);  // convert pf2 "back again"
	int x = 7;
	int y = pf1(&x);  // OK
}

void f(int);
int f(char);
void (*pf1)(int) = &f;  // void f(int)
int (*pf2)(char) = &f;  // int f(char);
void (*pf3)(char) = &f;  // error: no void f(char);

void f(int) noexcept;
void g(int);
void (*p1)(int) = f;  // OK: but we throw away useful information
void (*p2)(int) noexcept = f;  // OK: we preserve the noexcept info
void (*p3)(int) noexcept = g;  // error: we don't know that g doesnt't throw

using Pc = extern "C" void(int);  // error: linkage specification in alias
using Pn = void(int) noexcept;  // error: noexcept in alias

using CFT = int(const void*, const void*);
void ssort(void* base, size_t n, size_t sz, CFT cmp)
/*
Sort the "n" elements of vector "base" into increasing order
using the comparison function pointed to by "cmp".
The elements are of size "sz".

Shell sort(Knuth, Vol3, pg84)
*/
{
	for (int gap = n / 2; gap > 0; gap /= 2)
		for (int i = gap; i != n; ++i)
			for (int j = i - gap; j >= 0; j -= gap) {
				char* b = static_cast<char*>(base);  // necessary cast
				char* pj = b + j * sz;  // &base[j]
				char* pjg = b + (j + gap) * sz;  // &base[j+gap]
				if (cmp(pjg, pj) < 0) {  // swap base[j] and base[j+gap]
					for (int k = 0; k != sz; ++k) {
						char temp = pj[k];
						pj[k] = pjg[k];
						pjg[k] = temp;
					}
				}
			}
}

struct User {
	const char* name, *id;
	int dept;
};
vector<User> heads = {
	{"Ritchie D.M.", "dmr", 11271},
	{"Sethi R.", "ravi", 11272},
	{"Szymanski T.G.", "tgs", 11273},
	{"Schr yer N.L.", "nls", 11274},
	{"Schr yer N.L.", "nls", 11275},
	{"Kernighan B.W.", "bwk", 11276}
};
void print_id(vector<User>& v)
{
	for (auto& x : v)
		cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
}

int cmp1(const void* p, const void* q)  // compare name strings
{
	return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
}
int cmp2(const void* p, const void* q)  // compare dept numbers
{
	return static_cast<const User*>(p)->dept - static_cast<const User*>(q)->dept;
}
int cmp3(const User* p, const User* q)  // Compare ids
{
	return strcmp(p->name, q->name);
}

int main(int argc, char* argv[])
{
	cout << "Heads in alphabetical order:\n";
	ssort(&heads, sizeof(heads) / sizeof(User), sizeof(User), cmp1);
	print_id(heads);
	cout << '\n';
	
	cout << "Heads in order of department number:\n";
	ssort(&heads, sizeof(heads) / sizeof(User), sizeof(User), cmp2);
	print_id(heads);
	cout << '\n';

	cout << "Heads in alphabetical order:\n";
	sort(heads.begin(), heads.end(),
		[](const User& x, const User& y) { return x.name < y.name; }
	);
	print_id(heads);
	cout << '\n';
	
	cout << "Heads in order of department number:\n";
	sort(heads.begin(), heads.end(),
		[](const User& x, const User& y) { return x.dept < y.dept; }
	);
	print_id(heads);
}