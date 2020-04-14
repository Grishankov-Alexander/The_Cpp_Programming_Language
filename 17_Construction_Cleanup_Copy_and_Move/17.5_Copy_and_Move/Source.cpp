#include <array>
#include <utility>
#include <memory>
#include <algorithm>
using namespace std;


// 17.5.1 Copy
template<class T>
class Matrix {
	array<int, 2> dim;  // two dimensions
	T* elem;  // pointer to dim[0]*dim[1] elements of type T

public:
	Matrix(int d1, int d2) : dim{ d1, d2 }, elem{ new T[d1 * d2] } {}
	Matrix(const Matrix&);  // copy constructor
	Matrix& operator=(const Matrix&);  // copy assignment
	Matrix(Matrix&&);  // move constructor
	Matrix& operator=(Matrix&&);  // move assignment
	~Matrix() { delete[] elem; }

	int size() const { return dim[0] * dim[1]; }
};

template<class T>
Matrix<T>::Matrix(const Matrix& m)  // copy constructor
	: dim{ m.dim }, elem{ new T[m.size()] }
{
	uninitialized_copy(m.elem, m.elem + m.size(), elem);  // copy elements
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m)  // copy assignment
{
	if (dim[0] != m.dim[0] || dim[1] != m.dim[1])
		throw runtime_error("bad size in Matrix =");
	copy(m.elem, m.elem + m.size(), elem);
}
// or
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& m)
{
	Matrix tmp{ m };  // copy constructor
	swap(tmp, *this);
	return *this;
}


// 17.5.1.2 Copy of Bases
struct B1 {
	B1();
	B1(const B1&);
};
struct B2 {
	B2(int);
	B2(const B2&);
};
struct D : B1, B2 {
	D(int i) : B1{}, B2{ i }, m1{}, m2{ 2 * i } {}
	D(const D& a) : B1{ a }, B2{ a }, m1{ a.m1 }, m2{ a.m2 } {}
	B1 m1;
	B2 m2;
};

D d1{ 1 };  // construct with int argument
D d2{ d1 };  // copy construct


// 17.5.2 Move
template<class T>
Matrix<T>::Matrix(Matrix&& a)
	: dim{ a.dim }, elem{ a.elem }
{
	a.dim = { 0, 0 };
	a.elem = nullptr;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& a)
{
	swap(dim, a.dim);
	swap(elem, a.elem);
	return *this;
}

template<class T>
Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b)
{
	if (a.dim[0] != b.dim[0] || a.dim[1] != b.dim[1])
		throw runtime_error{ "unequal Matrix sizes in +" };
	Matrix res{ a.dim[0], a.dim[1] };
	constexpr auto n = a.size();
	for (int i = 0; i != n; ++i)
		res.elem[i] = a.elem[i] + b.elem[i];
	return res;
}