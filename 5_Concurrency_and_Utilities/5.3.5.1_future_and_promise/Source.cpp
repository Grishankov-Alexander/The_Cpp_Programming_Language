#include <future>
using namespace std;


void f(promise<X>& px)  // a task: place the result in px
{
	// ...
	try {
		X res;
		// ... compute a value for res
		px.set_value(res);
	}
	catch (...) {  // oops: couldn't compute res
		// pass the exception to the future's thread
		px.set_exception(current_exception());
	}
}

void g(future<X>& fx)  // a task: get the result from fx
{
	// ...
	try {
		X v = fx.get();  // if necessary, wait for the value to get computed
		// ... use v
	}
	catch (...) {  // oops: someone couldn't compute v
		// ... handle error
	}
}