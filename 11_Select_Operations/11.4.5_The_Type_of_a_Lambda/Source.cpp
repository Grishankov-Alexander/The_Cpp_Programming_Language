#include <functional>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;


auto rev = [&rev](char* b, char* e) {
	if (1 < e - b) { swap(*b, *--e); rev(++b, e); }
};  // error

void f(string& s1, string& s2)
{
	function<void(char* b, char* e)> rev =
		[&rev](char* b, char* e) { if (1 < e - b) { swap(*b, *--e); rev(++b, e); } };
	rev(&s1[0], &s1[0] + s1.size());
	rev(&s2[0], &s2[0] + s2.size());
}

void g(string& s1, string& s2)
{
	auto rev = [&](char* b, char* e) { while (1 < e - b) swap(*b++, *--e); };
	rev(&s1[0], &s1[0] + s1.size());
	rev(&s2[0], &s2[0] + s2.size());
}

double (*p1)(double) = [](double a) { return sqrt(a); };
double (*p2)(double) = [&](double a) { return sqrt(a); };  // error: the lambda captures
double (*p3)(int) = [](int a) { return sqrt(a); };