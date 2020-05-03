#include <string>
#include <functional>

/*template<class Key, class Value, bool(*cmp)(const Key&, const Key&)>
class map {};*/

bool insensitive(const std::string& x, const std::string& y)
{
	// ... compare case insensitive
	return x < y;
}

/*map<std::string, int, &insensitive> m;  // compare using insensitive*/

// or better:
template<typename Key, typename Value, typename Compare = std::less<Key>>
class map {
	Key key{};
	Value value{};
	Compare cmp{};
public:
	map() {}  // use the default comparison
	map(Compare c) : cmp{ c } {}  // provide other comparison
};

map<std::string, int> m1;  // cmp is std::less<string>{}
map<char, int, std::greater<char>> m2;  // compare with std::greater

using Cmp = bool(*)(const std::string&, const std::string&);
map<std::string, int, Cmp> m3{ &insensitive };
map<std::string, int, Cmp> m4{
	[](const std::string& a, const std::string& b) { return a > b; }
};