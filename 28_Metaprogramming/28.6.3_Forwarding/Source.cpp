#include <utility>
#include <iostream>
#include <string>

template<class F, class... Args>
void call(F&& f, Args&&... args)
{
	f(std::forward<Args>(args)...);
}

void g0() { std::cout << "g0()\n"; }
template<class T>
void g1(const T& t) { std::cout << "g1(): " << t << '\n'; }
void g1d(double d) { std::cout << "g1d(): " << d << '\n'; }
template<class T, class T2>
void g2(const T& t, T2&& t2) { std::cout << "g2(): " << t << ", " << t2 << '\n'; }

int main()
{
	call(g0);
	call(g1<int>, 1);
	call(g1<double>, 2.1);
	call(g1d, 2.1);
	call(g2<double, std::string>, 1, "World!");

	int i = 99;
	const char* p = "Trying";
	call(g2<double, std::string>, i, p);

	call([]() { std::cout << "l1()\n"; });
	call([](int i) { std::cout << "l2(): " << i << '\n'; }, 33);
	call([&i]() { std::cout << "l3(): " << i << '\n'; i = 100; });
	std::cout << i;
}