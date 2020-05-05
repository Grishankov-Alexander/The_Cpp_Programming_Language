

template<typename T, int N>
class Matrix;

template<typename T>
class Matrix<T, 0> {  // specialization for N==0
	T val;
};

template<typename T>
class Matrix<T, 1> {
	T* elem;
	int sz;  // number of elements
};

template<typename T>
class Matrix<T, 2> {
	T* elem;
	int dim1;  // number of rows
	int dim2;  // number of columns
};