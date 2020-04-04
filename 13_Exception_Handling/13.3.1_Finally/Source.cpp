#include <cstdlib>
#include <iostream>
using namespace std;


template <typename F>
struct Final_action {
	F clean;
	Final_action(F f) : clean{ f } {}
	~Final_action() { clean(); }
};
template<class F>
Final_action<F> finally(F f)
{
	return Final_action<F>(f);
}

void test()
// handle undisciplined resource acquisition
// demonastrate that arbitrary actions are possible
{
	int* p = new int{ 7 };
	int* buf = (int*)malloc(100 * sizeof(int));  // C-style allocation
	auto act1 = finally(
		[&] { delete p; free(buf); }
	);
	int var = 0;
	cout << "var: " << var << '\n';
	// nested block
	{
		var = 1;
		auto act2 = finally(
			[&] { var = 7; }
		);
		cout << "var: " << var << '\n';
	}  // act2 is invoked here
	cout << "var: " << var << '\n';
}  // act1 is invoked here
