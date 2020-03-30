

constexpr int ftbl[]{ 1, 2, 3, 5, 8, 13 };
constexpr int fib(int n)
{
	return (n < sizeof(ftbl) / sizeof(*ftbl)) ? ftbl[n] : fib(n);
}

template<typename T> class complex;
template<> class complex<float> {
public:
	explicit constexpr complex(const complex<double>&);
};
constexpr complex<float> z{ 2.0 };

constexpr const int* addr(const int& r) { return &r; }
static const int x = 5;
constexpr const int* p1 = addr(x);
constexpr int xx = *p1;
static int y;
constexpr const int* p2 = addr(y);  // OK
constexpr int yy = *p2;  // error: attempt to read a variable
constexpr const int* tp = addr(5);  // error: address of temporary