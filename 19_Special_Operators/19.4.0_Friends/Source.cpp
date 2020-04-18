

constexpr int rc_max{ 4 };

class Matrix;
class Vector {
	float v[rc_max];
	friend Vector operator*(const Matrix&, const Vector&);
};
class Matrix {
	Vector v[rc_max];
	friend Vector operator*(const Matrix&, const Vector&);
};

Vector operator*(const Matrix& m, const Vector& v)
{
	Vector r;
	for (int i = 0; i != rc_max; ++i) {  // r[i] = m[i]*v
		r.v[i] = 0;
		for (int j = 0; j != rc_max; ++j)
			r.v[i] += m.v[i].v[j] * v.v[j];
	}
	return r;
}

class List;
class List_iterator {
	int* next(List& l);
};
class List {
	friend int* List_iterator::next(List& l);
	friend class List_iterator;  // all List_iterator member functions
								// can access List representation
	int hello;
};
int* List_iterator::next(List& l) { return &l.hello; }

template<typename T>
class X {
	friend T;
	friend class T;  // redundant class
};