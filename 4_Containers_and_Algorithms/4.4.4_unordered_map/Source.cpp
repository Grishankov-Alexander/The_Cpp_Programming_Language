#include <unordered_map>
#include <string>
using namespace std;


// unordered_map is a hashed container (the best for lookup)
// unordered (hashed) means "containers don't require an ordering function"
unordered_map<string, int> phone_book{
	{ "David Hume", 123456 },
	{ "Karl Popper", 234567 },
	{ "Bertrand Arthur William Russell", 345678 }
};

int get_number(const string& s)
{
	return phone_book[s];
}