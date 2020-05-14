#include <type_traits>


template<class... Bases>
struct X : Bases... {
	X(const Bases&... b) : Bases(b)... {}
};

template<class... Types>
struct tuple {
	template<class T, class U, class = typename std::enable_if<sizeof...(Types) == 2>::type>
	tuple(T, U) {}
};
tuple<int, char> t1{ 3, 'g' };  // OK
tuple<int, char, double> t2{ 3, 'g' };  // error


int main()
{
	class Bx {}; class By {}; class Bz {};

	Bx bx{}; By by{}; Bz bz{};
	X<> x0;
	X<Bx> x1(bx);
	X<Bx> x2();  // WHY ?
	X<Bx, By> x3(bx, by);
	X<Bx, By, Bz> x4(bx, by, bz);
}