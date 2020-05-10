#include <type_traits>
#include <cstring>
using namespace std;


template<typename T>
void copy(T* dest, const T* src, int n)
{
	if (is_trivial<T>::value)
		memcpy(dest, src, n);  // use optimized memory copy
	else for (int i = 0; i != n; ++i) dest[i] = src[i];
}

template<typename T>
constexpr bool Is_pod() { return is_pod<T>::value; }
template<typename T>
constexpr bool Is_big() { return sizeof(T) > 100; }

template<class> class On_heap; template<class> class On_scope;
template<typename T>
using heap_or_scope = conditional<Is_big<T>(), On_heap<T>, On_scope<T>>::type;

heap_or_scope<double> small;  // scope
heap_or_scope<double[20000]> big;  // heap