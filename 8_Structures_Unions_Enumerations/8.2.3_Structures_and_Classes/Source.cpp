#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


struct Point {
	int x, y;
};
Point p0;  // danger: uninitialized if in local scope
Point p1{};  // default constructor: {{},{}}; that is{0,0}
Point p2{ 1 };  // the second member is default constructed: {1,{}}; that is {1,0}
Point p3{ 1, 2 };

struct Points {
	vector<Point> elem;  // must contain at least one Point
	Points(Point p0) { elem.push_back(p0); }
	Points(Point p0, Point p1) { elem.push_back(p0); elem.push_back(p1); }
	// ...
};
Points x0;  // error: no default constructor
Points x1{ {100, 200} };  // one Point
Points x2{ { 100, 200 }, { 300, 400 } };  // two Points

struct Address {
	string name;  // "Jim Dandy"
	int number;  // 11
	string street;  // "South St"
	string town;  // "New Providence"
	char state[2];  // 'N', 'J'
	char zip[5];  // 07974

	Address(const string& n, int nu, const string& s,
		const string& t, const string& st, int z);
};

Address::Address(const string& n, int nu, const string& s,
	const string& t, const string& st, int z)  // validate postal code
	: name{ n }, number{ nu }, street{ s }, town{ t }
{
	if (st.size() != 2)
		error("State abbreviation should be two characters");
	state = { st[0], st[1] };  // store postal code as chars
	ostringstream ost;  // an output string stream
	ost << z;  // extract chars from int
	string zi{ ost.str() };
	switch (zi.size()) {
	case 5:
		zip = { zi[0], zi[1], zi[2], zi[3], zi[4] };
		break;
	case 4:  // starts with '0'
		zip = { '0', zi[0], zi[1], zi[2], zi[3] };
		break;
	default:
		error("unexpected ZIP code format");
	}
}