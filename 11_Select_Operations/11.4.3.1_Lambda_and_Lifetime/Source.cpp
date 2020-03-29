#include <map>
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


void setup(Menu& m)
{
	Point p1, p2, p3;
	m.add("draw triangle", [&] { m.draw(p1, p2, p3); });  // probable disaster
	m.add("draw triangle", [=] { m.draw(p1, p2, p3) });
}


// 11.4.3.2 Namespace Names
namespace ns_names {
	template<typename U, typename V>
	ostream& operator<<(ostream& os, const pair<U, V>& p)
	{
		return os << "{" << p.first << ", " << p.second << "}";
	}

	void print_all(const map<string, int>& m, const string& label)
	{
		cout << label << ":\n{\n";
		for_each(m.begin(), m.end(),
			[](const pair<string, int>& p) { cout << p << '\n'; }
		);
		cout << "}\n";
	}
}


// 11.4.3.3 Lambda and this
class Request {
	function<map<string, string>(const map<string, string>&)> oper;  // operation
	map<string, string> values;  // arguments
	map<string, string> results;  // targets
public:
	Request(const string& s);  // parse and store request
	void execute()
	{
		[this]() { results = oper(values); };  // do oper to values yielding results
	}
};


// 11.4.3.4 mutable Lambdas
void algo(vector<int>& v)
{
	int count = v.size();
	std::generate(v.begin(), v.end(),
		[count]() mutable { return --count; });
}