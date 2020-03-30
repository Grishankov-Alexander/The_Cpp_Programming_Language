#include <vector>
using namespace std;


void f(int val, int& ref)
{
	++val;
	++ref;
}
void g()
{
	int i = 1;
	int j = 1;
	f(i, j);
}

float fsqrt(const float&);  // Fortran-style sqrt taking a ref argument
void g(double d)
{
	float r = fsqrt(2.0f);  // pass by reference to temp holding 2.0f
	r = fsqrt(r);  // pass reference to r
	r = fsqrt(d);  // pass reference to temp holding static_cast<float>(d)
}

void update(float& i);
void g(double d, float r)
{
	update(2.0f);  // error: const argument
	update(r);  // pass ref to r
	update(d);  // error: type conversion required
}

void f(vector<int>&);  // (non-const) lvalue reference argument
void f(const vector<int>&);  // const lvalue reference argument
void f(vector<int>&&);  // rvalue reference argument
void g(vector<int>& vi, const vector<int>& cvi)
{
	f(vi);  // call f(vector<int>&)
	f(cvi);  // call f(const vector<int>&)
	f(vector<int>{ 1, 2, 3, 4 });  // call f(vector<int>&&)
}