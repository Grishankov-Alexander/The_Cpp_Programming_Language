#include <thread>
#include <vector>
using namespace std;


void f(vector<double>& v);  // function do something with v

struct F {  // function object: do something with v
	vector<double>& v;
	F(vector<double>& vv) : v{ vv } {}
	void operator()();  // application operator
};

int main()
{
	vector<double> some_vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<double> vec2{ 10, 11, 12, 13, 14 };

	thread t1{ f, some_vec };  // f(some_vec) executes in a separate thread
	thread t2{ F{ vec2 } };  // F(vec2)() executes in a separate thread

	t1.join();
	t2.join();
}