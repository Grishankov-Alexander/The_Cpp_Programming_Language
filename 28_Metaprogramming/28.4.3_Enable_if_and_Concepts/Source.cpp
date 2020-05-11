#include <vector>
#include <complex>
using namespace std;


template<bool B, class T = void>
struct enable_if { typedef T type; };
template<class T>
struct enable_if<false, T> {};  // no ::type
template<bool B, class T = void>
using Enable_if = typename enable_if<B, T>::type;

template<typename T>
Enable_if<Ordered<T>()> fct(T*, T*);  // optimized implementation

template<typename T>
Enable_if<!Ordered<T>()> fct(T*, T*);  // nonoptimized

void f(vector<int>& vi, vector<complex<double>>& vc)
{
	if (vi.size() == 0 || vc.size() == 0) throw runtime_error{ "message" };
	fct(&vi.front(), &vi.back());  // call optimized
	fct(&vc.front(), &vc.back());  //  nonoptimized
}