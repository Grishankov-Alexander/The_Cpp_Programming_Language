class Nonlocal {
public:
	void destroy() { this->~Nonlocal(); }
private:
	~Nonlocal();  // don't destroy implicitly
};

void user()
{
	Nonlocal a;  // cannot create object with inaccessible destructor
	Nonlocal* p = new Nonlocal;  // OK
	delete p;  // error
	p->destroy();  // OK
}