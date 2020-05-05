#include <climits>
#include <vector>
#include <typeinfo>

template<typename T> T max_value();
template<>
constexpr int max_value<int>() { return INT_MAX; }
template<>
constexpr char max_value<char>() { return CHAR_MAX; }

template<typename Iter>
using Value_type = typename Iter::value_type;

constexpr auto i = max_value<int>();
constexpr Value_type<std::vector<int>> i2 = 122;

template<typename Iter>
Iter my_algo(Iter p)
{
	auto x = max_value<Value_type<Iter>>();
	return p;
}

int main()
{
	if (typeid(i2) == typeid(i)) return 0;
}