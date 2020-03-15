#include <map>
#include <string>
#include <algorithm>
using namespace std;


// look for an element that fulfills a specified requirement, a predicate.

struct Greater_than {
	int val;
	Greater_than(int v) : val{ v } {}
	bool operator()(const pair<string, int>& r) { return r.second > val; }
};

void f(map<string, int>& m)
{
	auto p = find_if(m.begin(), m.end(), Greater_than(42));
	// ...

	// with lambda expr
	int cxx = count_if(m.begin(), m.end(),
		[](const pair<string, int>& r) { return r.second > 42; });
}
