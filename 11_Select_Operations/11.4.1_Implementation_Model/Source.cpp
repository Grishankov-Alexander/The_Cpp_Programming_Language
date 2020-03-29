#include <vector>
#include <iostream>
#include <ostream>
#include <algorithm>
using namespace std;


void print_modulo(const vector<int>& v, ostream& os, int m)
// output v[i] to os if v[i]%m==0
{
	for_each(begin(v), end(v), [&os, m](int x) { if (x % m == 0) os << x << '\n'; });
}

class Modulo_print {
	ostream& os;  // members to hold the capture list
	int m;
public:
	Modulo_print(ostream& s, int mm) : os{ s }, m{ mm } {}  // capture
	void operator()(int x) const
	{
		if (x % m == 0) os << x << '\n';
	}
};
void print_modulo(const vector<int>& v, ostream& os, int m)
{
	for_each(begin(v), end(v), Modulo_print{ os, m });
}