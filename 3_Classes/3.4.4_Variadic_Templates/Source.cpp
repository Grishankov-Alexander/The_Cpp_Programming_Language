#include <iostream>


template<typename T>
void g(const T& x)
{
	std::cout << x << " ";
}

void f() {}  // do nothing

// ellipsis (...) is used to indicate "the rest" of a list
template<typename T, typename... Tail>
void f(T head, Tail... tail)
{
	g(head);  // do something to head
	f(tail...);  // try again with tail
}

int main()
{
	std::cout << "first: ";
	f(1, 2.2, "hello");
	std::cout << "\nsecond: ";
	f(0.2, 'c', "yuck", 0, 1, 2);
	std::cout << '\n';
}