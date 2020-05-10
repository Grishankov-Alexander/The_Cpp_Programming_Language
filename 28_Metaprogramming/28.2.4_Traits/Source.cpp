#include <iterator>
using namespace std;

template<typename Iter>
Iter search(Iter p, Iter q, typename iterator_traits<Iter>::value_type val)
{
	typename iterator_traits<Iter>::difference_type m = q - p;
}

// better
template<typename Iter>
Iter search(Iter p, Iter q, decltype(*p) val)
{
	auto x = *p;  // if we don't need to name *p's type
	auto m = q - p;  // q-p type

	using value_type = decltype(*p);  // if we want to name *p's type
	using difference_type = decltype(q - p);
}