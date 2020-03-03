#include <iostream>
#include <complex>
#include <vector>
using namespace std;


// 2.2.1 Hello, World!
namespace hello_world
{
	double square(double x)
	{
		return x * x;
	}

	void print_square(double x)
	{
		cout << "The square of " << x << " is " << square(x) << "\n";
	}

	int main()
	{
		std::cout << "Hello, World!\n";
		print_square(1.234);
		return 0;
	}
}


// 2.2.2 Types, Variables, and Arithmetic
namespace types_variables_arithmetic
{
	void some_function()
	{
		double d = 2.2;
		int i = 7;
		d = d + i;
		i = d * i;
	}

	// Initialization:
	void initialization()
	{
		cout << sizeof(char) << "\n";
		double d1 = 2.3;
		double d2{ 2.3 };  // curly-brace-delimited initializer lists
		complex<double> z1 = 1;
		complex<double> z2{ d1, d2 };
		complex<double> z3 = { 1, 2 };
		vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8 };
		int i1 = 7.2;  // converts to 7
		// int i2{ 7.2 };  // error (no conversion will be made)
		// int i3 = { 7.2 };  // same
		auto b = true;
		auto ch = 'x';
		auto i = 123;
		auto d = 1.2;
		auto z = sqrt(2.22);
	}
}


// 2.2.3 Constants
namespace constants
{
	constexpr double square(double x)
	{
		return x * x;
	}
	double sum(const vector<double>&);  // will not modify argument
	const int dmv = 17;
	int var = 17;
	constexpr double max1 = 1.4 * square(dmv); // OK, evaluate at compile time
	//constexpr double max2 = 1.4 * square(var);  // error: var is not constexpr
	const double max3 = 1.4 * square(var);  // Ok, evaluate at run time
	vector<double> v{ 1.2, 3.4, 5.6 };
	//const double s1 = sum(v);  // Ok, evaluate at run time
	//constexpr double s2 = sum(v);  // Error, sum(v) is not constexpr
}


// 2.2.4 Tests and Loops
namespace tests_and_loops
{
	bool accept()
	{
		cout << "Do you want to proceed (y or n)?\n";
		char answer = 0;
		cin >> answer;
		if (answer == 'y') return true;
		return false;
	}
	bool accept2()
	{
		cout << "Do you want to proceed (y or n)?\n";
		char answer = 0;
		cin >> answer;
		switch (answer) {
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			cout << "I'll take that for a no.\n";
			return false;
		}
	}
	bool accept3()
	{
		int tries{ 1 };
		while (tries < 4) {
			cout << "Do you want to proceed (y or n)?\n";
			char answer = 0;
			cin >> answer;
			switch (answer) {
			case 'y':
				return true;
			case 'n':
				return false;
			default:
				cout << "Sorry, I don't understand that.\n";
				++tries;
			}
		}
		cout << "I'll take that for a no.\n";
		return false;
	}
}


// 2.2.5 Pointers, Arrays, and Loops
namespace pointers_arrays_loops
{
	char v[6]{ 'a', 'b', 'c', 'd', 'e', 'f' };  // Array of 6 chars
	char* p = &v[3];  // Pointer to char

	void copy_fct()
	{
		int v1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		int v2[10];
		for (auto i = 0; i != 10; ++i) {
			v2[i] = v1[i];
		}
	}

	// range-for-statement
	void print()
	{
		int v[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (auto x : v)
			cout << x << "\n";
		for (auto x : { 10, 21, 32, 43, 54, 65 })
			cout << x << "\n";
	}

	// For declarations:
	// T a[n] - array of Ts
	// T* p - pointer to T
	// T& r - reference to T

	// For expressions:
	// *p - contents of a pointer
	// &o - address of an object

	void increment()
	{
		int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		for (auto& x : v)  // x doesn't copy, but refer to an element in v
			cout << x++ << ", " << x << "\n";
	}

	int count_x(char* p, char x)
		// count the number of occurences of x in p[]
		// p is assumed to point to a zero-terminated array of char (or to nothing)
	{
		if (p == nullptr) return 0;
		int count = 0;
		for (; *p != 0; ++p)
			if (*p == x) ++count;
		return count;
	}
}


int main()
{
	pointers_arrays_loops::increment();
	return 0;
}