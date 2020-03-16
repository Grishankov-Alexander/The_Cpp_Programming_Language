#include <thread>
#include <vector>
#include <iostream>
using namespace std;


void f(const vector<double>& v, double* res);  // take input from v; place result in *res

class F {
private:
	const vector<double>& v;  // source of input
	double* res;  // target for output
public:
	F(const vector<double>& vv, double* p) : v{ vv }, res{ p } {}
	void operator()();  // pace result in *res
};

int main()
{
	vector<double> some_vec, vec2;
	double res1, res2;

	// f(some_vec, &res1) executes in a separate thread
	thread t1{ f, some_vec, &res1 };
	// F{vec2, &res2}() executes in a separate thread
	thread t2{ F{ vec2, &res2 } };

	t1.join();
	t2.join();

	cout << res1 << ", " << res2 << "\n";
}