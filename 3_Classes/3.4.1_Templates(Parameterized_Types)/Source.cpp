#include <list>
#include <string>
#include <iostream>


template<typename T>
class Vector {
private:
	T* elem;  // points to an array of sz elements of type T
	int sz;
public:
	Vector(int s);  // constructor: establish invariant, acquire resources
	~Vector() { delete[] elem; }  // destructor: release resources

	// copy and move operations ...

	T& operator[](int i);
	const T& operator[](int i) const;
	int size() const { return sz; }
};

template<typename T>
Vector<T>::Vector(int s)
{
	if (s < 0) throw Negative_size{};
	elem = new T[s];
	sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
	if (i < 0 || size() <= i)
		throw std::out_of_range{ "Vector::operator[]" };
	return elem[i];
}

Vector<char> vc(200);  // vector of 200 characters
Vector<std::string> vs(17);  // vector of 17 strings
Vector<std::list<int>> vli(45);  // vector of 45 lists of integers

void write(const Vector<std::string>& vs)
{
	for (int i = 0; i != vs.size(); ++i)
		std::cout << vs[i] << '\n';
}

// To support range-for loops
template<typename T>
T* begin(Vector<T>& x)
{
	return &x[0];  // pointer to first element
}

template<typename T>
T* end(Vector<T>& x)
{
	return x.begin() + x.size();  // pointer to one-past-last element
}

void f2(const Vector<std::string>& vs)
{
	for (auto& s : vs)
		std::cout << s << '\n';
}