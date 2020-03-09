

// 3.3.2 Moving Containers

Vector operator+(const Vector& a, const Vector& b)
{
	if (a.size() != b.size())
		throw Vector_size_mismatch{};
	Vector res(a.size());
	for (int i = 0; i != a.size(); ++i)
		res[i] = a[i] + b[i];
	return res;
}

void f(const Vector& x, const Vector& y, const Vector& z)
{
	Vector r;
	// ...
	r = x + y + z;  // expensive
	// ...
}

class Vector {
	// ...
public:
	Vector(const Vector& a);  // copy constructor
	Vector& operator=(const Vector& a);  // copy assignment

	// && means rvalue reference
	Vector(Vector&& a);  // move constructor
	Vector& operator=(Vector&& a);  // move assignment
};

Vector::Vector(Vector&& a)
	: elem{ a.elem },  // "grab" the elements from a
	sz{ a.sz }
{
	a.elem = nullptr;  // now a has no elements
	a.sz = 0;
}

Vector f()
{
	Vector x(1000);
	Vector y(1000);
	Vector z(1000);
	// ...
	z = x;  // we get a copy
	y = std::move(x);  // we get a move
	return z;  // we get a move
}