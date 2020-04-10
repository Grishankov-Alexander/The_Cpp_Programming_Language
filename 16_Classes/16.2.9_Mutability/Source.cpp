#include <string>
using namespace std;


// 16.2.9.3 mutable
class Date {
public:
	string string_rep() const;  // string representation
private:
	mutable string cache;
	mutable bool cache_valid;
	void compute_cache_value() const;  // fill (mutable) cache
};

string Date::string_rep() const
{
	if (!cache_valid) {
		compute_cache_value();
		cache_valid = true;
	}
	return cache;
}

void f(Date& d, const Date& cd)
{
	string s1 = d.string_rep();
	string s2 = cd.string_rep();  // OK
}


// 16.2.9.4 Mutability through indirection
struct cache {
	bool valid;
	string rep;
};

class Date {
public:
	string string_rep() const;  // string repr
private:
	cache* c;  // initialize in constructor
	void compute_cache_value() const;  // fill what cache refers to
};

string Date::string_rep() const
{
	if (!c->valid) {
		compute_cache_value();
		c->valid = true;
	}
	return c->rep;
}