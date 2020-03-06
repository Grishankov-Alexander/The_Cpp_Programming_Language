#include <vector>
#include <iostream>


class Shape {
public:
	virtual Point center() const = 0;  // pure virtual
	virtual void move(Point to) = 0;
	virtual void draw() const = 0;  // draw on current "Canvas"
	virtual void rotate(int angle) = 0;
	virtual ~Shape() {}  // destructor
};

void rotate_all(std::vector<Shape*>& v, int angle)  // rotate v's elements by angle degrees
{
	for (auto p : v)
		p->rotate(angle);
}

class Circle : public Shape {
public:
	Circle(Point p, int rad);  // constructor
	Point center() const { return x; }
	void move(Point to) { x = to; }
	void draw() const;
	void rotate(int) {}  // nice simple algorithm
private:
	Point x;  // center
	int r;  // radius
};

class Smiley : public Circle {  // use the Circle as the base for a face
public:
	Smiley(Point p, int r) : Circle{ p, r }, mouth{ nullptr } {}
	~Smiley() { for (auto p : eyes) delete p; delete mouth; }
	
	void move(Point to);
	void draw() const;
	void rotate(int);

	void add_eye(Shape* s) { eyes.push_back(s); }
	void set_mouth(Shape* s);
	virtual void wink(int i);  // wink eye number i
private:
	std::vector<Shape*> eyes;
	Shape* mouth;
};

void Smiley::draw() const
{
	Circle::draw();
	for (auto p : eyes) p->draw();
	mouth->draw();
}

enum class Kind { circle, triangle, smiley };
Shape* read_shape(std::istream& is)  // read shape descriptions from input stream
{
	// ... read shape header from is and find its kind k ...
	switch (k) {
	case Kind::circle: 
		// read circle data{ Point, r } into p and r
		return new Circle{ p, r };
	case Kind::triangle:
		// read triangle data { Point1, Point2, Point3 } into p1, p2, p3
		return new Triangle{ p1, p2, p3 };
	case Kind::smiley:
		// read smiley data { Point, int, Shape, Shape, Shape } into p, r, e1, e2, m
		Smiley* ps = new Smiley{ p, r };
		ps->add_eye(&e1);
		ps->add_eye(&e2);
		ps->set_mouth(&m);
		return ps;
	}
}

void user()
{
	std::vector<Shape*> v;
	while (std::cin)
		v.push_back(read_shape(std::cin));
	draw_all(v);  // call draw() for each element
	rotate_all(v, 45);  // call rotate(45) for each element
	for (auto p : v) delete p;  // remember to delete elements
}

namespace unique_pointers {
	std::unique_ptr<Shape> read_shape(std::istream& is)
	{
		// read shape from is and find its Kind k
		switch (k) {
		case Kind::circle:
			// read circle data - p and r
			return std::unique_ptr<Shape>{ new Circle{ p, r } };
			// ...
		}
	}

	void user()
	{
		std::vector<std::unique_ptr<Shape>> v;
		while (std::cin)
			v.push_back(read_shape(std::cin));
		draw_all(v);  // call draw() for each Shape
		rotate_all(v, 45);  // call rotate(45) for each element
	}  // all Shapes implicitly destroyed
}
