#include <complex>
#include <vector>

template<typename T>
T sqrt(T);

template<typename T>
std::complex<T> sqrt(std::complex<T>);

double sqrt(double);

void f(std::complex<double> z)
{
	sqrt(2.0);  // sqrt(double)
	sqrt(z);  // sqrt<double>(complex<double>)
	sqrt(2);  // sqrt<int>(int)
}

template<typename T>
T max(T, T);

const int s = 7;
void k()
{
	max(1, 2);  // max<int>
	max('a', 'b');  // max<char>
	max(s, 7);  // max<int>(int{s}, 7)

	max('a', 1);  // error: ambiguous: max<char> or max<int> ?
	max(2.7, 4);  // error, ambiguous: max<double> or max<int> ?
}


// 23.5.3.1 Ambiguity Resolution
void f()
{
	max<int>('a', 1);  // OK
	max<double>(2.7, 4);  // OK
}

inline int max(int i, int j) { return max<int>(i, j); }
inline double max(double d, int i) { return max<double>(d, i); }
inline double max(int i, double d) { return max<double>(i, d); }
inline double max(double d1, double d2) { return max<double>(d1, d2); }

void g()
{
	max(2, 3.5);  // OK
	max('a', 1);  // max<int>
}


// 23.5.3.2 Argument Substitution Failure
template<typename Iter>
typename Iter::value_type mean(Iter b, Iter e);

template<typename T>
T mean(T*, T*);

void f(std::vector<int>& v, int* p, int n)
{
	auto x = mean(v.begin(), v.end());  // mean(Iter,Iter)
	auto y = mean(p, p + n);  // call mean(T*,T*)
}

template<typename Iter>
Iter mean(Iter first, Iter last)
{
	typename Iter::value_type val = *first;
}
template<typename T>
T* mean(T* first, T*);

void f(std::vector<int>& v, int* p, int n)
{
	auto x = mean(v.begin(), v.end());  // OK, call mean(Iter, Iter)
	auto y = mean(p, p + n);
}


// 23.5.3.3 Overloading and Derivation
template<typename T>
class B {};
template<typename T>
class D : public B<T> {};

template<typename T> void f(B<T>*);

void g(B<int>* pb, D<int>* pd)
{
	f(pb);  // f<int>(B<int>*)
	f(pd);  // f<int>(static_cast<B<int>*>(pd))
}


// 23.5.3.4 Overloading and Non-Deduced Parameters
template<typename T, typename C>
T get_nth(C& c, int n) { return T{ c[n] }; }  // get the nth element

struct Index { operator int(); };

void f(std::vector<char>& v, short s, Index i)
{
	int i1 = get_nth<int>(v, 2);
	int i2 = get_nth<int>(v, s);  // standard conversion: short to int
	int i3 = get_nth<int>(v, i);  // user-defined conversion: Index to int
}