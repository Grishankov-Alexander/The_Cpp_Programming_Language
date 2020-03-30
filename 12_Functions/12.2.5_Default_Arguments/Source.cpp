class complex {
	double re, im;
public:
	complex(double r = {}, double i = {}) : re{ r }, im{ i } {}  // construct complex from two scalars
};

class X {
public:
	static int def_arg;
	void f(int = def_arg);
};
int X::def_arg = 7;
void g(X& a)
{
	a.f();  // maybe f(7)
	a.def_arg = 9;
	a.f();  // f(9)
}

int f(int, int = 0, char* = nullptr);  // OK
int g(int = 0, int, char* = nullptr);  // error
int nasty(char *= nullptr);  // syntax error
void f(int x = 7);
void f(int x = 8);  // error: cannot repeat default args
