#include <vector>
#include <ostream>
#include <algorithm>
using namespace std;


void print_modulo(const vector<int>& v, ostream& os, int m)
{
	class Modulo_print {
		ostream& os;
		int m;
	public:
		Modulo_print(ostream& s, int mm) : os{ s }, m{ mm } {}
		void operator()(int x) const
		{
			if (x % m == 0) os << x << '\n';
		}
	};
	for_each(begin(v), end(v), Modulo_print{ os, m });
}

void print_modulo(const vector<int>& v, ostream& os, int m)
{
	auto Modulo_print = [&os, m](int x) { if (x % m == 0) os << x << '\n'; };
	for_each(begin(v), end(v), Modulo_print);
}

template<class C>
void print_modulo(const C& v, ostream& os, int m)
{
	for (auto x : v)
		if (x % m == 0) os << x << '\n';
}
