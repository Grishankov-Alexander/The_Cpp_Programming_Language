#include <iostream>

using namespace std;


void f(Shape& r, Shape* p)
{
	typeid(r);  // type of the object referred to by r
	typeid(*p);  // type of the object pointed to by p
	typeid(p);  // probably a mistake (Shape*)
}

struct Poly {  // polymorphic base
	virtual void f() {};
};

struct Non_poly {};  // no virtual functions

struct D1 : Poly {};
struct D2 : Non_poly {};

void f(Non_poly& npr, Poly& pr)
{
	cout << typeid(npr).name() << '\n';  // name of "Non_poly" or a class derived from it
	cout << typeid(pr).name() << '\n';
}

void g()
{
	D1 d1;
	D2 d2;
	f(d2, d1);
	f(*static_cast<Non_poly*>(nullptr), *static_cast<Poly*>(nullptr));
}

int main()
{
	g();
}