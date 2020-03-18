#include <limits>  // implementation-defined aspects of fundamental types
#include <cstdint>  // variety of integers
#include <cstddef>  // widely used aliases
#include <iostream>
using namespace std;


int16_t x{ 0xaabb };  // 2 bytes
int64_t xxxx{ 0xaaaabbbbccccdddd };  // 8 bytes
int_least16_t y;  // at least 2 bytes
int_least32_t yy;  // at least 4 bytes
int_fast32_t z;  // the fastest int type with at least 4 bytes

// size_t is an implementation-defined unsigned integer type
// that can hold the size in bytes of every object.
size_t a;
void* allocate(size_t n);  // get n bytes and return pointer to object of unknown type

// ptrdiff_t is a signed integer type for holding the result
// of subtracting two pointers to get a number of elements
ptrdiff_t b;

int main()
{
	cout << "size of int: " << sizeof(1) << '\n';
	cout << "size of long: " << sizeof(1L) << '\n';
	cout << "size of long long: " << sizeof(1LL) << '\n';

	cout << "largest float == " << numeric_limits<float>::max() << '\n';
	cout << "char is signed: " << numeric_limits<char>::is_signed << '\n';
}