#include <vector>

template<typename T, template<typename> class C>
class Xrefd {
	C<T> mems;
	C<T*> refs;
};

template<typename T>
using Vec = std::vector<T>  // use default allocator

Xrefd<int, Vec> x1;