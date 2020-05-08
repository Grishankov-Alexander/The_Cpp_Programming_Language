// Parameterization
class A {};

template<typename X>
class Ct {  // interface expressed in terms of the parameter
	X mem;
public:
	X f();
	int g();
	void h(X);
};

template<>
class Ct<A> {  // specialization for A
	A* mem;  // representation differs from the primary template
public:
	A f();
	int g();
	void h(A);
	void k(int);  // added functionality
};

Ct<A> cta;  // specialization for A
class B {};
Ct<B> ctb;


// Hierarchy
class X {};

class Cx {  // interface expressed in terms of types in scope
	X mem;
public:
	virtual X& f();
	virtual int g();
	virtual void h(X&);
	virtual Cx& hello();
};

class DA : public Cx {  // derived class
public:
	X& f() override;
	int g() override;
	void h(X&) override;
};

class DB : public Cx {
	DB* p;  // more extensive representation
public:
	X& f();
	int g() override;
	void h(X&) override;
	DB& hello() override;
	void k(int);  // added functionality
};

Cx& cxa{ *new DA };  // cxa is an interface to a DA
Cx& cxb{ *new DB };   // interface to a DB