#include <utility>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


struct Assoc {
	vector<pair<string, int>> vec;  // vector of {name,value} pairs
	int& operator[](const string&);
	const int& operator[](const string&) const;
};
int& Assoc::operator[](const string& s)
// search for s; return a reference to its value if found;
// otherwise, make a new pair {s,0} and return a reference to its value
{
	for (auto x : vec)
		if (s == x.first) return x.second;
	vec.push_back({ s, 0 });  // initial value: 0
	return vec.back().second;  // return last element
}

int main(int argc, char* argv[])  // count the occurences of each word on input
{
	Assoc values;
	string buf;
	while (cin >> buf) ++values[buf];
	for (auto x : values.vec)
		cout << '{' << x.first << ',' << x.second << '}' << endl;
}