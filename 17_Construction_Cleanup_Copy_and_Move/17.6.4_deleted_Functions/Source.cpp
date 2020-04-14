

class Base {
public:
	Base(const Base&) = delete;  // disallow copying
	Base& operator=(const Base&) = delete;
	Base(Base&&) = delete;  // disallow moving
	Base& operator=(Base&&) = delete;
};
Base x1;
Base x2{ x1 };  // error: no copy constructor

template<class T>
T* clone(T* p)  // return copy of *p
{
	return new T{ *p };
}
class Foo; class Shape;
Foo* clone(Foo* p) = delete;  // don't try to clone a Foo
void f(Shape* ps, Foo* pf)
{
	Shape* ps2 = clone(ps);
	Foo* pf2 = clone(pf);  // error: clone(Foo*) deleted
}

struct Z {
	Z(double);  // can init with double
	Z(int) = delete;  // can't init with int
};
void f()
{
	Z z1{ 1 };  // error: Z(int) deleted
	Z z2{ 1.0 };  // OK
}

class Not_on_stack {
	~Not_on_stack() = delete;
};
class Not_on_free_store {
	void* operator new(size_t) = delete;
};
void f2()
{
	Not_on_stack v1;  // error: can't destroy
	Not_on_free_store v2;  // OK
	Not_on_stack* p1 = new Not_on_stack;  // OK
	Not_on_free_store* p2 = new Not_on_free_store;  // error: can't allocate
}