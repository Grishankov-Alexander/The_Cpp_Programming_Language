#include <iostream>
#include <vector>
#include <string>
using namespace std;


void f()
{
	string s;
	while (cin >> s) {
		if (s == "\r\n") break;
	}
}

int find_prime(vector<int>& v)
{
	for (int x : v) {
		if (!prime(x)) continue;
		return x;
	}
}