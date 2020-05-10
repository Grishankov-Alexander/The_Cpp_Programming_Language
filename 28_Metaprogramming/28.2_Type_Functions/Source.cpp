#include <type_traits>
#include <iostream>
#include <string>
#include <array>
using namespace std;

void f()
{
	if (is_polymorphic<int>::value) cout << "Big surprise!";
}

enum class Axis : char { x, y, z };
enum flags { off, x = 1, y = x << 1, z = x << 2, t = x << 3 };
typename underlying_type<Axis>::type chr;  // x is a char
underlying_type_t<flags> ii = 2;  // int

template<typename T, int N>
struct Array_type {
	using type = T;
	static const int dim = N;
};

typename Array_type<int, 5>::type iii = 4;  // int
constexpr auto dim = Array_type<char, 228>::dim;  // dim is 228


template<typename T>
struct Scoped {
	Scoped() : x() {}
	T& operator*() { return x; }
	T* operator->() { return &x; }
	
	Scoped(const Scoped&) = delete;
	Scoped& operator=(const Scoped&) = delete;
private:
	T x;  // the object
};

template<typename T>
struct On_heap {
	On_heap() : p{ new T } {}  // allocate
	~On_heap() { delete p; }  // deallocate
	On_heap(const On_heap&) = delete;
	On_heap& operator=(const On_heap&) = delete;

	T& operator*() { return *p; }
	T* operator->() { return p; }
	auto operator[](size_t n) -> typename T::value_type&  { return (*p)[n]; }
private:
	T* p;
};

template<typename T>
struct Obj_holder {
	static constexpr int stack_max_size
		= sizeof(string);  // max size of the object we want on the stack
	using type = typename conditional
		<sizeof(T) <= stack_max_size,  // if fits on the stack
		Scoped<T>,  // use type for placing on the stack
		On_heap<T>  // else: for placing on the heap
		>::type;
};

template<class T> using Obj_holder_t = typename Obj_holder<T>::type;

void g()
{
	typename Obj_holder<double>::type sco1;  // double goes on the stack
	Obj_holder_t<array<double, 200>> heap1;  // the array goes on the free stor
	*sco1 = 7.7;  // Scoped provides pointer-like access
	heap1[77] = 99;  // On_heap provides same
}