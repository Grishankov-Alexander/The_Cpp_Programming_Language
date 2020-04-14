#include <stdexcept>
using namespace std;


class Matrix {
public:
	Matrix& operator+=(const Matrix&);  // return-by-reference
private:
	int dim[2];
	double* elem;
};

Matrix& Matrix::operator+=(const Matrix& a)
{
	if (dim[0] != a.dim[0] || dim[1] != a.dim[1])
		throw std::exception{ "bad Matrix += argument" };
	double* p = elem;
	double* q = a.elem;
	double* end = p + dim[0] * dim[1];
	while (p != end)
		*p++ = *q++;
	return *this;
}

Matrix operator+(const Matrix& a, const Matrix& b)  // pass by reference, return by value
{
	Matrix res{ a };
	return res += b;
}