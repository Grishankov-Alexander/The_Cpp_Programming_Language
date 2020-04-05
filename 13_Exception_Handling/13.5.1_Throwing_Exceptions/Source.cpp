#include <stdexcept>
#include <type_traits>
#include <vector>
using namespace std;


class No_copy {
	No_copy(const No_copy&) = delete;  // prohibit copying
};
class My_error {
	// ...
};
void f(int n)
{
	switch (n) {
	case 0: throw My_error{};  // OK
	case 1: throw No_copy{};  // error: can't copy a No_copy
	default: throw My_error;  // error: My_error is a type
	}
}

struct My_error2 : runtime_error {
	const char* what() const noexcept { return "My_error2"; }
};
void g(int n)  // throw some exception
{
	if (n) throw runtime_error{ "runtime error" };
	else throw My_error2{};
}
void f(int n)  // see what exception g() throws
{
	try {
		g(n);
	}
	catch (exception & e) {
		cerr << e.what() << '\n';
	}
}


// 13.5.1.2 The noexcept Operator
template<typename T>
void my_fct(T& x) noexcept(is_pod<T>());
template<typename T>
void call_f(vector<T>& v) noexcept(noexcept(f(v[0])))
{
	for (auto x : v) f(x);
}
template<class T, size_t N>
void swap(T(&a)[N], T(&b)[N]) noexcept(noexcept(swap(*a, *b)));

