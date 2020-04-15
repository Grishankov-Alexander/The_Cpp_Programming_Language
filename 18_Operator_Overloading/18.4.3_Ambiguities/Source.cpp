

class X {
public: X(int); X(const char*);
};
class Y {
public: Y(int);
};
class Z { public:
	Z(X);
};

X f(X);
Y f(Y);
Z g(Z);

void k1()
{
	f(1);  // error: ambiguous f(X(1)) or f(Y(1))?
	f(X{ 1 });  // OK
	f(Y{ 1 });  // OK
	g("Mack");  // error: two user-defined conversions needed - g(Z{X{"Mack"}})
	g(Z{ "Mack" });  // OK: g(Z{X{"Mack"}})
	g(X{ "Doc" });  // OK: g(Z{X{"Doc"}})
}

class XX { XX(int); };
void h(double);
void h(XX);

void k2()
{
	h(1);  // h(double{1}) or h(XX{1})? h(double{1})!
}