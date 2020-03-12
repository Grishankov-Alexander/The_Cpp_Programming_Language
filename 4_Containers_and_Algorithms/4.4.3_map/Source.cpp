#include <string>
#include <map>
using namespace std;


// map is a search tree (a red-black tree / balanced binary tree)
// 1. this container is optimized for lookup
map<string, int> phone_book = {
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russell", 345678}
};

int get_number(const string& s)
{
	// if s is not found, map will create new key s
	// with the default value of a corresponding type
	return phone_book[s];
}