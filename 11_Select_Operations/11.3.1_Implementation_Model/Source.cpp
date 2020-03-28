#include <vector>
using namespace std;


vector<double> v{ 1, 2, 3.14 };
// steps:
const double temp[] = { double{1}, double{2}, double{3.14} };
const initializer_list<double> tmp(temp, sizeof(temp) / sizeof(double));
vector<double> v(tmp);

void f()
{
	initializer_list<int> lst{ 1, 2, 3 };
	cout << *lst.begin() << '\n';
	*lst.begin() = 2;  // error: lst is immutable
}
