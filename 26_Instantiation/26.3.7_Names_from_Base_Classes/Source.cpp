

void g(int);
void g2(int);

struct B {
	using Type = int;
	void g(char);
	void g2(char);
};

template<typename T>
class X : public T {
public:
	typename T::Type m;
	using typename T::Type;
	Type m2;
	using T::g2;

	void f()
	{
		g(3);  // call ::g(int)
		this->g(3);  // T::g
		T::g(3);  // T::g
		g2(3);  // T::g2
	}
};

void h(X<B> x)
{
	x.f();
}

template<typename T>
class Matrix_base {  // memory for matrices
public:
	int size() const { return sz; }
protected:
	T* elem;
	int sz;
};

template<typename T, int N>
class Matrix : public Matrix_base<T> {  // N-dimensional matrix
public:
	T* data() { return this->elem; }  // "this" required
};