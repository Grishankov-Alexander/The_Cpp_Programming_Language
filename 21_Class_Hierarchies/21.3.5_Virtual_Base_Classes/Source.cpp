#include <string>
using namespace std;

class Storable {
public:
	Storable(const string& s);  // store in file named s
	virtual void read() = 0;
	virtual void write() = 0;
	virtual ~Storable() {}
protected:
	string file_name;

	Storable(const Storable&) = delete;
	Storable& operator=(const Storable&) = delete;
};

class Transmitter : public virtual Storable {
public:
	void write() override;
};

class Receiver : public virtual Storable {
public:
	void write() override;
};

class Radio  // will have only 1 Storable object
	: public Transmitter, public Receiver {
public:
	void write() override;
};


// 21.3.5.1 Constructing Virtual Bases
struct V {
	V(int i);
};

struct A {
	A();
};

struct B : virtual V, virtual A {
	B() : V{ 1 } {};  // default constructor: must initialize base V
};

struct C : virtual V {
	C(int i) : V{ i } {}  // must initialize base v
};

class D : virtual public B, virtual public C {
	// implicitly gets the virtual base V from B and C
	// implicitly gets virtual base A from B
	// must initialize virtual bases without default constructors (C and V)
public:
	D() { /*...*/ }  // error: no default constructor for C and V
	D(int i) : C{ i } {}  // error: no default constructor for V
	D(int i, int j) : C{ i }, V{ j } {}   // OK
};


// 21.3.6.1 Overriding Virtual Base Functions
class Window {
public:
	virtual void set_color(int) = 0;
	virtual void prompt() = 0;
};

class Window_with_border : public virtual Window {
	void set_color(int) override;
};

class Window_with_menu : public virtual Window {
	void prompt() override;
};

class My_window
	: public Window_with_border,
	public Window_with_menu {};

Window_with_border wwb{};  // abstract
My_window mw{};  // OK