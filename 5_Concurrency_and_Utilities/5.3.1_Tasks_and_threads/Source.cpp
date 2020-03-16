#include <thread>
#include <iostream>
using namespace std;

// a task is a function of a function object
// that will be executed concurrently
void f();  // function

struct F {  // function object
	void operator()();  // F's call operator
};

void user()
{
	thread t1{ f };  // f() executes in separate thread
	thread t2{ F() };  // F()() executes in separate thread

	t1.join();  // wait for t1
	t2.join();  // wait for t2
}

void bad_f() { cout << "Hello "; }
struct bad_F {
	void operator()() { cout << "Parallel World!\n"; }
};