#include <type_traits>
using namespace std;


template<typename T>
constexpr bool Is_arithmetic()
{
	return is_arithmetic<T>::value;
}

bool b1 = Is_arithmetic<int>();  // yes, int is an arithmetic type
bool b2 = Is_arithmetic<string>();  // no, string is not an arithmetic type

template<typename Scalar>
class Complex {
	Scalar re, im;
public:
	static_assert(Is_arithmetic<Scalar>(), "Sorry, I only support complex of arithmetic types");
};