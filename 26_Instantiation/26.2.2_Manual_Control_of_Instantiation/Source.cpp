

template<typename T>
class vector {
	vector* p;
	vector& r;
public:
	T operator[](int) { return T{}; }
};

template<typename T, class U>
T convert(U);

template class vector<int>;  // instantiate class and all its members
template int vector<int>::operator[](int);  // instantiate member function
template int convert<int>(double);  // nonmember function

template<typename T> class My_vector;
extern template class My_vector<int>;  // suppresses implicit instantiation
										// explicitly instantiate elsewhere

int main() {}