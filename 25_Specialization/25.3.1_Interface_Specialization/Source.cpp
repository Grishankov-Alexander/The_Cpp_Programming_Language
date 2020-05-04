

template<typename T>
class complex {
	T re, im;
public:
	complex(const T& r = T{}, const T& i = T{})
		: re{ r }, im{ i } {}
	complex(const complex&);
	template<typename X>
	complex(const complex<X>&);  // conversion from complex<X> to complex<T>

	complex& operator=(const complex&);
	complex& operator=(const T&);
	complex& operator+=(const T&);
	
	template<typename X>
	complex& operator=(const complex<X>&);
	template<typename X>
	complex& operator+=(const complex<X>&);
};

template<>
class complex<float> {
	float re, im;
public:
	constexpr complex() : re{}, im{} {}
	complex& operator=(float);
	complex& operator+=(float);
	complex& operator=(const complex&);
};

template<>
class complex<double> {
	double re{}, im{};
public:
	constexpr complex(double r = 0.0, double i = 0.0);
	constexpr complex(const complex<float>&) {};
	explicit constexpr complex(const complex<long double>&);
};

int main()
{
	constexpr complex<double> cd{ complex<float>{} };
}