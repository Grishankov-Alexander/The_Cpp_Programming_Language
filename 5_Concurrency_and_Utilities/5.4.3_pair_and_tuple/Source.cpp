#include <utility>
#include <tuple>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


template<typename Forward_iterator, typename T, typename Compare>
pair<Forward_iterator, Forward_iterator>
equal_range(Forward_iterator first, Forward_iterator last, const T& vla, Compare cmp);

// compare names
auto rec_eq = [](const Record& r1, const Record& r2) { return r1.name < r2.name; };

void v(const vector<Record>& v)  // assume that v is sorted on its "name" field
{
	auto er = equal_range(v.begin(), v.end(), Record{ "Reg" }, rec_eq);
	for (auto p = er.first; p != er.second; ++p)  // print all equal records
		cout << *p;
}

void f(vector<string>& v)
{
	auto pp = make_pair(v.begin(), 2);  // pp is a pair<vector<string>::iterator, int>
}

tuple<string, int, double> t2{ "Sild", 123, 3.14 };  // the type is explicitly specified

auto t = make_tuple(string("Herring"), 10, 1.23);  // the type is deduced
												// t is tuple<string, int, double>

string s = get<0>(t);  // get first element of tuple
int x = get<1>(t);
double d = get<2>(t);