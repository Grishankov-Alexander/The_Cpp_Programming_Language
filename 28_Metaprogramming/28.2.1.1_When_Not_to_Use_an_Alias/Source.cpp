#include <type_traits>
#include <vector>
using namespace std;


struct Error { Error() = delete; };

// if T is integral, Result is unsigned T 
template<class T>
using Result = typename conditional<is_integral<T>::value,
	typename make_unsigned<T>::type, Error>::type;

Result<int> ui1 = 333;  // unsigned int
Result<char> uc1 = 228;  // unsigned char

// make_unsigned should delay its evaluation
template<template<class...> class Fct, class... Args>
using Delay = Fct<Args...>;
template<class T>
using Result2 = typename conditional<is_integral<T>,
	Delay<make_unsigned_t, T>, Error>::type;