

template<typename T>
class Vector {  // general vector type
	T* v;
	int sz;
public:
	Vector();
	explicit Vector(int);

	T& elem(int i) { return v[i]; }
	T& operator[](int i) { return elem(i); }

	void swap(Vector&);
};

template<>
class Vector<void*> {  // complete specialization
	void** p;
public:
	explicit Vector(int i);
	void*& operator[](int i) { return p[i]; }
};

template<typename T>
class Vector<T*> : private Vector<void*> {  // partial specializaation
public:
	using Base = Vector<void*>;

	Vector() {}
	explicit Vector(int i) : Base(i) {}

	T*& elem(int i) { return reinterpret_cast<T*&>(Base::operator[](i)); }
	T*& operator[](int i) { return elem(i); }
};

Vector<int> vi;  // T is int
Vector<char*> vac;  // T is char
Vector<int**> vppi;  // T is int*