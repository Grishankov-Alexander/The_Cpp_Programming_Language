#include <iostream>
using namespace std;

// 2.3.1 Structures
namespace structures
{
	struct Vector {
		int sz;  // number of elements
		double* elem;  // pointer to elements
	};
	Vector v;

	void vector_init(Vector& v, int s)
	{
		v.elem = new double[s];  // allocate an array of s doubles
		v.sz = s;
	}

	double read_and_sum(int s)
	// read s doubles from cin and return their sum; s is assumed to be positive
	{
		Vector v;
		vector_init(v, s);  // allocate s elements for v
		cout << "Type " << s << " double numbers:\n";
		for (int i = 0; i != s; ++i)
			cin >> v.elem[i];  // read into elements
		double sum = 0;
		for (int i = 0; i != s; ++i)
			sum += v.elem[i];  // take the sum of the elements
		cout << "\nSum: " << sum << "\n";
		return sum;
	}

	void f(Vector v, Vector& rv, Vector* pv)
	{
		int i1 = v.sz;  // access through name
		int i2 = rv.sz;  // access through reference
		int i3 = pv->sz;  // access through pointer
	}
}


// 2.3.2 Classes
namespace classes
{
	class Vector {
	public:
		Vector(int s) : elem{ new double[s] }, sz{ s } {}  // construct a Vector
		double& operator[](int i) { return elem[i]; }  // element access: subscripting
		int size() { return sz; }
	private:
		double* elem;  // pointer to the elements
		int sz;  // the number of elements
	};
	Vector v(6);  // a Vector with 6 doubles

	double read_and_sum(int s)
	{
		Vector v(s);
		cout << "Type " << s << " doubles:\n";
		for (int i = 0; i != v.size(); ++i)
			cin >> v[i];
		double sum = 0;
		for (int i = 0; i != v.size(); ++i)
			sum += v[i];
		cout << "Sum: " << sum << "\n";
		return sum;
	}
}


// 2.3.3 Enumerations
namespace enumerations
{
	enum class Color { red, blue, green };
	enum class Traffic_light { green, yellow, red };
	Color col = Color::red;
	Traffic_light light = Traffic_light::red;
	// Color x = red;  // error: which red?
	// Color y = Traffic_light::red;  // error: that red is not a Color
	Color z = Color::red;  // OK
	// int i = Color::red;  // error: Color::red is not an int
	// Color c = 2;  // error: 2 is not a Color

	// We can define operators for enums:
	Traffic_light& operator++(Traffic_light& t)
		// prefix increment: ++
	{
		switch (t) {
		case Traffic_light::green: return t = Traffic_light::yellow;
		case Traffic_light::yellow: return t = Traffic_light::red;
		case Traffic_light::red: return t = Traffic_light::green;
		}
	}
	Traffic_light next = ++light;  // next becomes Traffic_light::green
}


int main(int argc, char* argv)
{
	structures::read_and_sum(5);
	classes::read_and_sum(3);
}