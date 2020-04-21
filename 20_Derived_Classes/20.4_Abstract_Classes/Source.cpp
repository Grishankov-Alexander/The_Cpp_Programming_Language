#include <list>
#include <initializer_list>


class Shape {  // abstract class
public:
	virtual void rotate(int) = 0;  // pure virtual function
	virtual void draw() const = 0;
	virtual bool is_closed() const = 0;

	virtual ~Shape();
};
Shape s;  // error: variable of abstract class

class Point { /*...*/ };
class Circle : public Shape {
public:
	Circle(Point _center, int _radius)
		: center{ _center }, radius{ _radius }
	{};

	void rotate(int) override;
	void draw() const override {};
	bool is_closed() const override { return true; }
private:
	Point center;
	int radius;
};
Circle c{ Point{}, 5 };

class Polygon : public Shape {  // abstract
public:
	bool is_closed() const override { return true; }
};
Polygon poly = {};  // error: object of abstract class

class Irregular_polygon : public Polygon {
public:
	Irregular_polygon(std::initializer_list<Point>);

	void rotate(int) override;
	void draw() const override final;
private:
	std::list<Point> lp;
};
Irregular_polygon ipoly{ Point{}, Point{} };  // OK
