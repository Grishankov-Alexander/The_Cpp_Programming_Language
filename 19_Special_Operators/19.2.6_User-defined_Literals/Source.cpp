#include <complex>
#include <string>
using namespace std;


constexpr complex<double> operator""i(long double d)  // imaginary literal
{
	return { 0, d };  // complex is a literal type
}
string operator""s(const char* p, size_t n)  // std::string literal
{
	return string{ p, n };  // requires free-store allocation
}

template<typename T> void f(const T&);
void g()
{
	f("Hello");  // pass const char*
	f("Hello"s);  // five-character string object
	auto z = 2. + 1i;  // complex{ 2, 1 }
}

class Bignum { public: Bignum(const char*); };
Bignum operator""x(const char* p)
{
	return Bignum{ p };
}
void f(Bignum);
void g()
{
	f(12341235x);  // passes "12341235"
}

string operator""s(const char* p, size_t n);
string s12{ "one two"s };  // calls operator""s("one two", 7)

string operator""SS(const char* p);  // will work not as expected
string s12 = "one two"SS;  // error: no applicable operator
string s13 = 13SS;


// template literal operator
template<char... chars>
constexpr int operator""_b3();  // base 3
//auto v1 = 201_b3;  // OK: means operator""_b3<'2','0','1'>(); 1*3^0 + 0*3^1 + 2*3^2 == 19
//auto v2 = 241_b3;  // error: 4 isn't a base 3 digit

constexpr int ipow(int x, int n)  // x^n for n >= 0
{
	return (n > 0) ? x * ipow(x, n - 1) : 1;
}
template<char c>  // handle the single ternary digit case
constexpr int b3_helper()
{
	static_assert(c < '3', "not a ternary digit");
	return c - '0';  // ASCII '0' = 48 dec 
}
template<char c, char... tail>  // peel off one ternary digit
constexpr int b3_helper()
{
	static_assert(c < '3', "not a ternary digit");
	return (c - '0') * ipow(3, sizeof...(tail)) + b3_helper<tail...>();
}
template<char... chars>
constexpr int operator""_b3()
{
	return b3_helper<chars...>();
}

constexpr auto v1 = 201_b3;  // OK: means operator""_b3<'2','0','1'>(); 1*3^0 + 0*3^1 + 2*3^2 == 19
auto v2 = 241_b3;  // error: 4 isn't a base 3 digit