#include <memory>

template<typename T, typename Allocator = std::allocator<T>>
class vector;

using Cvec = vector<char>;
Cvec vc{ 'a', 'b', 'c' };

template<typename T>
using Vec = vector<T, My_alloc<T>>;
Vec<int> fib{ 0, 1, 1, 2, 3, 5, 8, 13 };

vector<char, std::allocator<char>> vc2 = vc;

template<int>
struct int_exact_traits {  // int_exact_traits<N>::type is a type with N bits
	using type = int;
};

template<>
struct int_exact_traits<8> { using type = char; };
template<>
struct int_exact_traits<16> { using type = short; };

template<int N>
using int_exact = int_exact_traits<N>::type;  // alias

int_exact<8> a = 'c';  // int_exact<8> is a char (8 bits)