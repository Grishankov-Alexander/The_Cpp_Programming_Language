#include <type_traits>
#include <cstring>
using namespace std;


struct S0 {};  // a POD
struct S1 { int a; };  // a POD
struct S2 { int a; S2(int aa) : a{ aa } {} };  // not a POD (no default constructor)
struct S3 { int a; S3() {}; S3(int aa) : a{ aa } {} };  // a POD (user-defined default constructor)
struct S4 { int a; S4(int aa) : a{ aa } {} S4() = default; };  // a POD
struct S5 { virtual void f(); /*...*/ };  // not a POD (has a virtual func)

struct S6 : S1 {};  // a POD
struct S7 : S0 { int b; };  // a POD
struct S8 : S1 { int b; };  // not a POD (data in both S1 and S8)
struct S9 : S0, S1 {};  // a POD

template<typename T>
void mycopy(T* to, const T* from, int count)
{
	if (is_pod<T>::value)
		memcpy(to, from, count * sizeof(T));
	else
		for (int i = 0; i != count; ++i)
			to[i] = from[i];
}