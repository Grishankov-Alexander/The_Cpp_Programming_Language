#include <vector>
#include <utility>
using namespace std;


class Circle;
class Triangle;

class Shape {
public:
	virtual bool intersect(const Shape&) const = 0;
	virtual bool intersect(const Circle&) const = 0;
	virtual bool intersect(const Triangle&) const = 0;
};

class Circle : public Shape {
public:
	bool intersect(const Shape& s) const override { return s.intersect(*this); }
	bool intersect(const Circle& c) const override { return true; }
	bool intersect(const Triangle& t) const override { return true; }
};

class Triangle : public Shape {
public:
	bool intersect(const Shape& s) const override { return s.intersect(*this); }
	bool intersect(const Circle& c) const override { return true; }
	bool intersect(const Triangle& t) const override { return true; }
};

void do_something(Shape& s1, Shape& s2)
{
	if (s1.intersect(s2)) { /* the two shapes overlap */ }
}

void test(Circle& c, Triangle& t)
{
	vector<pair<Shape*, Shape*>> vs{
		{&c, &c}, { &c, &t }, { &t, &c }, { &t, &t }
	};
	for (auto p : vs)
		p.first->intersect(*p.second);
}