#include <iostream>
#include <type_traits>
#include <typeinfo>


template<typename T>
constexpr bool Input_iterator()
// Is T an iterator ?
{
	return true;
}
template<typename T, typename U>
constexpr bool Equality_comparable()
// Could T and U be compared for equality ?
{
	return std::is_same<T, U>::value;
}


template<typename Val>
struct Forward {  // for checking find()
	Forward();
	Forward(const Forward&);
	Forward operator=(const Forward&);
	bool operator==(const Forward&);
	bool operator!=(const Forward&);
	void operator++();
	Val& operator*();
	typedef Val value_type;
};

template<typename Iter>
using Value_type = typename Iter::value_type;

template<typename Iter, typename Val>
Iter find(Iter b, Iter e, Val x)
{
	static_assert(Input_iterator<Iter>(), "find(): Iter is not a Forward iterator");
	static_assert(Equality_comparable<Value_type<Iter>, Val>(),
		"find(): value type doesn't match iterator");
	while (b != e) {
		if (*b == x) return b;
		++b;
	}
	return b;
}

/*void f()
{
	auto p = find(Forward<int>{}, Forward<int>{}, 7);
}*/

int main()
{
	Value_type<Forward<int>> i = 7;
	std::cout << typeid(i).name();
}