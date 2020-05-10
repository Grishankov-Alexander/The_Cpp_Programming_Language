#include <type_traits>
#include <iostream>
using namespace std;


struct X {
	void operator()(int x) { cout << "X::operator()(" << x << ")\n"; }
};
struct Y {
	void operator()(int y) { cout << "Y::operator()(" << y << ")\n"; }
};

template<bool B, typename X, typename Y>
using Conditional = typename conditional<B, X, Y>::type;

void f()
{
	typename conditional<(sizeof(int) > 4), X, Y>::type{}(8);  // make an X or Y and call it
	Conditional<(sizeof(int) > 4), X, Y>{}(8);  // same
	Y{}(8);  // same

	using Z = Conditional<is_polymorphic<X>::value, X, Y>;
	Z zz;
	zz(7);
}