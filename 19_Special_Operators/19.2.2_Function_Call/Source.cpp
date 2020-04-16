#include <complex>
#include <list>
#include <vector>
using namespace std;

template<typename T>
class Add {
	complex<T> val;
public:
	Add(complex<T> c) : val{ c } {}
	Add(T r = 0, T i = 0) : val{ r, i } {}

	void operator()(complex& c) const
	{
		c += val;  // add a value to argument
	}
};

template<typename Iter, typename Fct>
Fct for_each(Iter b, Iter e, Fct f)
{
	while (b != e) f(*b++);
	return f;
}

template<typename T>
void h(vector<complex<T>>& vec, list<complex<T>>& lst, complex<T> z)
{
	for_each(vec.begin(), vec.end(), Add{ 2, 3 });
	for_each(lst.begin(), lst.end(), Add{ z });
}

template<typename T>
void h(vector<complex<T>>& vec, list<complex<T>>& lst, complex<T> z)
{
	for_each(vec.begin(), vec.end(), [](complex& c) { c += { 2, 3 }; });
	for_each(vec.begin(), vec.end(), [&z](complex& c) { c += z; });
}