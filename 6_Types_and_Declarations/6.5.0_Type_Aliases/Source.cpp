

using Pchar = char*;  // pointer to char
using PF = int(*)(double);  // pointer to function taking a double and returning an int

template<class T>
class vector {
	using value_type = T;  // every container has a value type
};

Pchar p1 = nullptr;  // p1 is a char*
char* p2 = p1;  // fine

typedef int int32_t;  // equivalent to using int32_t = int
typedef short int16_t;
typedef void(*PtoF)(int);  // equivalent to using PtoF = void(*)(int)

template<typename T>
using Vector = std::vector<T, My_allocator<T>>;

using Char = char;
using Uchar = unsigned Char;  // error
using Uchar = unsigned char;  // OK