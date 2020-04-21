#include <string>
#include <vector>
#include <stdexcept>

struct B1 {
	void f(int);
};
struct B2 {
	void f(double);
};
struct D : public B1, B2 {
	using B1::f;
	using B2::f;
	void f(char);
};

void use(D d)
{
	d.f(1);  // call D::f(int)
	d.f(2.0);  // call D::f(double)
	d.f('a');  // call D::f(char)
}


// 20.3.5.1 Inhereting Constructors
namespace inh_constr {
	struct B1 {
		B1(int);
	};
	struct D1 : B1 {
		using B1::B1;  // implicitly declares D1(int)
		std::string s;  // has default constructor
		int x;  // forgot to provide initialization
	};
	void test()
	{
		D1 d{ 6 };  // d.x is not initialized
		D1 e;  // D1 has no default constructor
	}
	
	template<class T>
	class Vector : std::vector<T> {
	public:
		using std::vector<T>::vector;  // inherit constructors
		T& operator[](size_t i) { check(i); return std::vector<T>::operator[](i); }
		const T& operator[](size_t i) const { check(i); return std::vector<T>::operator[](i); }
		void check(size_t i) { if (this->size() <= i) throw std::range_error{ "Vector::check()" }; }
	};

	Vector<int> v{ 1, 2, 3, 4 ,5 };
	int val1 = v[2];
}