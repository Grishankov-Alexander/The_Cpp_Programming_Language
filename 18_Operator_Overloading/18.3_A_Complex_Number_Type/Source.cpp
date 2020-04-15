


// 18.3.1 Member and Nonmember Operators
class complex {
	double re, im;
public:
	constexpr complex(double r = 0, double i = 0) : re{ r }, im{ i } {}

	constexpr complex& operator+=(complex a);  // needs access to representation

	constexpr double real() const { return re; }
	void real(double r) { re = r; }
	constexpr double imag() const { return im; }
	void imag(double i) { im = i; }
};

constexpr complex& complex::operator+=(complex a)
{
	re += a.re;
	im += a.im;
	return *this;
}

constexpr complex operator+(complex a, complex b)
{
	return a += b;  // access representation through +=
}

void f(complex x, complex y, complex z)
{
	complex r1{ x + y + z };  // r1 = operator+(operator+(x,y),z)
	complex r2{ x };  // r2 = x
	r2 += y;  // r2.operator+=(y)
	r2 += z;
}


// 18.3.4 Literals
constexpr complex operator""_i(long double d) { return { 0, (double)d }; }
constexpr complex z2{ 1.2, 12e3 };
constexpr complex z1{ 1.2 + 12e3_i };


// 18.3.5 Accessor Functions
constexpr bool operator==(complex a, complex b)
{
	return a.real() == b.real() && a.imag() == b.imag();
}
constexpr bool b1{ z2 == z1 };
