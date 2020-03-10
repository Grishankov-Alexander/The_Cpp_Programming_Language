#include <string>


using size_t = unsigned int;

template<typename T>
class Vector {
public:
	using value_type = T;
	// ...
};

// every std container provides value_type as the name of its value type
template<typename C>
using Element_type = typename C::value_type;

template<typename Container>
void algo(Container& c)
{
	// Make a Vector of the same value type as container
	Vector<Element_type<Container>> vec;
}

template<typename Key, typename Value>
class Map {
	// ...
};

template<typename Value>
using String_map = Map<std::string, Value>;

String_map<int> m;  // m is a Map<string, int>