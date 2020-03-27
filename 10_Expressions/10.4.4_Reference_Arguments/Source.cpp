class complex {
public:
	constexpr complex(double re = 0.0, double im = 0.0);
	constexpr complex(const complex<float>&);
	explicit constexpr complex(const complex<long double>&);

	constexpr double real() const;  // read the real part
	void real(double);  // set the real part
	constexpr double imag() const;  // read the imag part
	void imag(double);  // set the imag part

	complex<double>& operator=(double);
	complex<double>& operator+=(double);
	// ...
};

constexpr complex<float> z1{ 1, 2 };  // note: <float> not <double>
constexpr double re = z1.real();
constexpr double im = z1.imag();
constexpr complex<double> z2{ re, im };  // z2 becomes a copy of z1
constexpr complex<double> z3{ z1 };  // z3 becomes a copy of z1
