#include <type_traits>
#include <complex>
using namespace std;


template<typename T>
constexpr bool Is_class() { return is_class_v<T>; }
template<bool B, typename T>
using Enable_if = typename enable_if<B, T>::type;


template<typename T>
struct Smart_pointer {
	T& operator*();  // return reference to underlying object
	Enable_if<Is_class<T>(), T>* operator->();  // select a member (for classes only)
};

void f(Smart_pointer<double> p, Smart_pointer<complex<double>> q)
{
	auto d1 = *p;  // OK
	auto c1 = *q;  // OK
	auto d2 = q->real();  // OK
	auto d3 = p->real();  // error: p doesn't point to a class object
}