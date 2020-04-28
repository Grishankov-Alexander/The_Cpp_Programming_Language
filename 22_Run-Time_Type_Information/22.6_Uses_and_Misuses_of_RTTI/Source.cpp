#include <typeinfo>
#include <vector>
using namespace std;


// misuse of run-time type information
void rotate(const Shape& r)
{
	if (typeid(r) == typeid(Circle)) { /*...*/ }
	else if (Triangle* p = dynamic_cast<Triangle*>(&r)) { /*...*/ }
	else if (typeid(r) == typeid(Square)) { /*...*/ }
}

// also misuse
class Object { /* polymorphic */ };
class Container : public Object {
public:
	void put(Object*);
	Object* get();
};
class Ship : public Object {};
Ship* f(Ship* ps, Container* c)
{
	c->put(ps);  // put the Ship into the container
	Object* p = c->get();
	if (Ship* q = dynamic_cast<Ship*>(p))  // run-time check that object is a Ship
		return q;
	else { /* do something else */ }
}

// better
Ship* f(Ship* ps, vector<Ship*>& c)
{
	c.push_back(ps);
	return c.back();  // retreive a Ship from the container
}