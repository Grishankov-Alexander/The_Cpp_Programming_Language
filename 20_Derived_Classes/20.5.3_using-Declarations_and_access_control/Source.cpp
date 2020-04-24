
class B {
private:
	int a;
protected:
	int b;
public:
	int c;
};

class D : public B {
public:
	using B::a;  // error: B::a is private
	using B::b;  // make B::b publicly available through D
	using B::c;
};

class BB : private B {  // give access to B::b and B::c
public:
	using B::b;
	using B::c;
};

BB* bb = new BB;
int bc = bb->c;