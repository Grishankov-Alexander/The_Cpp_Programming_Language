#include <string>
#include <iostream>


// 28.7.1 Units
template<int M, int K, int S>
struct Unit { enum { m = M, kg = K, s = S }; };

using M = Unit<1, 0, 0>;  // meter
using Kg = Unit<0, 1, 0>;
using S = Unit<0, 0, 1>;
using MpS = Unit<1, 0, -1>;
using MpS2 = Unit<1, 0, -2>;

template<class U1, class U2>
struct Uplus {
	using type = Unit<U1::m + U2::m, U1::kg + U2::kg, U1::s + U2::s>;
};
template<class U1, class U2>
using Unit_plus = typename Uplus<U1, U2>::type;

template<class U1, class U2>
struct Uminus {
	using type = Unit<U1::m - U2::m, U1::kg - U2::kg, U1::s - U2::s>;
};
template<class U1, class U2>
using Unit_minus = typename Uminus<U1, U2>::type;


// 28.7.2 Quantitys
template<class U>
struct Quantity {
	double val;
	constexpr explicit Quantity(double d) : val{ d } {}
};

template<class U>
Quantity<U> operator+(Quantity<U> x, Quantity<U> y)
{
	return Quantity<U>{ x.val + y.val };
}
template<class U>
Quantity<U> operator-(Quantity<U> x, Quantity<U> y)
{
	return Quantity<U>{ x.val - y.val };
}

template<class U1, class U2>
Quantity<Unit_plus<U1, U2>> operator*(Quantity<U1> x, Quantity<U2> y)
{
	return Quantity<Unit_plus<U1, U2>>{ x.val* y.val };
}
template<class U1, class U2>
Quantity<Unit_plus<U1, U2>> operator/(Quantity<U1> x, Quantity<U2> y)
{
	return Quantity<Unit_minus<U1, U2>>{ x.val / y.val };
}

template<class U>
Quantity<U> operator*(Quantity<U> x, double y)
{
	return Quantity<U>{ x.val* y };
}
template<class U>
Quantity<U> operator*(double x, Quantity<U> y)
{
	return Quantity<U>{ y.val * x };
}


// 28.7.3 Unit Literals
constexpr Quantity<M> operator""_m(long double d) { return Quantity<M>{ (double)d }; }
constexpr Quantity<Kg> operator""_kg(long double d) { return Quantity<Kg>{ (double)d }; }
constexpr Quantity<S> operator""_s(long double d) { return Quantity<S>{ (double)d }; }

constexpr Quantity<M> operator""_km(long double d) { return Quantity<M>{ (double)d * 1000 }; }
constexpr Quantity<Kg> operator""_g(long double d) { return Quantity<Kg>{ (double)d / 1000 }; }


// 28.7.4 Utility Functions
template<typename U>
Quantity<Unit_plus<U, U>> square(Quantity<U> x)
{
	return Quantity<Unit_plus<U, U>>{ x.val* x.val };
}

template<typename U>
bool operator==(Quantity<U> x, Quantity<U> y)
{
	return x.val == y.val;
}
template<class U>
bool operator!=(Quantity<U> x, Quantity<U> y)
{
	return x.val != y.val;
}

std::string suffix(int u, const char* x)
{
	std::string suf;
	if (u) {
		suf += x;
		if (u > 1) suf += '0' + u;
		if (u < 0) {
			suf += '-';
			suf += '0' - u;
		}
	}
	return suf;
}

template<class U>
std::ostream& operator<<(std::ostream& os, Quantity<U> v)
{
	return os << v.val << suffix(U::m, "m") << suffix(U::kg, "kg") << suffix(U::s, "s");
}


int main(int argc, char* argv[])
{
	auto distance = 10.0_m;
	auto time = 20.2_s;

	//Quantity<MpS2> acceleration = distance / square(time);

	Quantity<M> x{ 10.5 };
	Quantity<S> y{ 2 };
	Quantity<MpS> speed{ 10 };
	auto double_speed = speed * 2;
	auto z = speed * speed * speed;
	
	std::cout << "z = " << z;
}