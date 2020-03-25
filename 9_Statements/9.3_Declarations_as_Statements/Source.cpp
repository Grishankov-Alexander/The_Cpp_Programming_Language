#include <iostream>
#include <vector>
#include <string>
using namespace std;


void f(vector<string>& v, int i, const char* p)
{
	if (p == nullptr) return;
	if (i < 0 || v.size() <= i) error("bad index");
	string s = v[i];
	if (s == p) {
		// ...
	}
}

void use()
{
	string s1;  // ""
	s1 = "The best is the enemy of the good.";
	string s2{ "Voltaire" };
}

void input()
{
	int buf[max];
	int count = 0;
	for (int i; cin >> i;) {
		if (i < 0) error("unexpected negative value");
		if (count == max) error("buffer overflow");
		buf[count++] = i;
	}
}