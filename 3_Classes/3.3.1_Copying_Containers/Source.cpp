
// 3.3 Copy and Move
void test(complex z1)
{
	complex z2{ z1 };  // copy initialization
	complex z3;
	z3 = z2;  // copy assignment
}

// 3.3.1 Copying Containers
void bad_copy(Vector v1)
{
	Vector v2 = v1;  // copy v1's representation into v2
	v1[0] = 2;  // v2[0] is now also 2!
	v2[1] = 3;  // v1[1] is now also 3!
}

class Vector {
private:
	double* elem;  // elem points to an array of sz doubles
	int sz;
public:
	Vector(int s);  // constructor: establish invariant, acquire resources
	~Vector() { delete[] elem; }  // destructor: release resources

	Vector(const Vector& a);  // copy constructor
	Vector& operator=(const Vector& a);  // copy assignment

	double& operator[](int i);
	const double& operator[](int i) const;

	int size() const;
};

Vector::Vector(const Vector& a)
	: elem{ new double[sz] },  // allocate space for elements
	sz{ a.sz }
{
	for (int i = 0; i != sz; ++i)
		elem[i] = a.elem[i];
}

Vector& Vector::operator=(const Vector& a)
{
	double* p = new double[a.sz];
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i];
	delete[] elem;  // delete old elements
	elem = p;
	sz = a.sz;
	return *this;
}