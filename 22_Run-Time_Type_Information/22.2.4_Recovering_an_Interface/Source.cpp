#include <memory>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Shape { public: virtual void draw() const = 0; };

class Io_obj {
public:
	virtual Io_obj* clone() const = 0;  // polymorphic
	virtual ~Io_obj() {}
};

struct Io_circle : Shape, Io_obj {
public:
	Io_circle(istream&);  // init from istream
	Io_circle* clone() const override  // use copy constructor
	{
		return new Io_circle{ *this };
	}
	static Io_obj* new_circle(istream& is)  // for io_map
	{
		return new Io_circle{ is };
	}  

	void draw() const override;
};

using Pf = Io_obj* (istream&);  // pointer to function returning Io_obj
map<string, Pf> io_map;  // maps strings to creation functions
string get_word(istream& is);  // read a word from is

Io_obj* get_obj(istream& is)
{
	string str = get_word(is);  // read initial word
	if (auto f = io_map[str])  // look up for function
		return f(is);  // call function
}

void user()
{
	// open istream ss that holds shapes
	istream ss{ file };
	unique_ptr<Io_obj> p{ get_obj(ss) };  // read object from stream
	if (auto sp = dynamic_cast<Shape*>(p.get())) {
		sp->draw();  // use the Shape
	}
	else { /* oops: non-shape */ }
}


template<class T>
struct Io : T, Io_obj {
public:
	Io(istream&);  // init from input stream
	Io<T>* clone() const override { return new Io<T>{ *this }; }
	static Io* new_io(istream& is) { return new Io{ is }; }  // for io_map
};

using Io_circle = Io<Circle>;

void f(Io<Shape>& ios)
{
	Shape* ps = &ios;
}

using Io_date = Io<Date>;  // wrap concrete type
using Io_int = Io<int>;  // error: cannot derive from built-in type

template<class T>
struct Io : Io_obj {
	T val;

	Io(istream&);
	Io* clone() const override { return new Io{ *this }; }
	static Io* new_io(istream& is) { return new Io{ is }; }
};

using Io_int = Io<int>;  // wrap built-in type

template<typename T>
T* get_val(Io_obj* p)
{
	if (auto pp = dynamic_cast<Io<T>*>(p))
		return &pp->val;
	return nullptr;
}

void user()
{
	unique_ptr<Io_obj> p{ get_obj(ss) };  // read object from stream
	if (auto sp = get_val<Shape>(p.get()))
		sp->draw();  // use the shape
	else { /*oops*/ }

}

