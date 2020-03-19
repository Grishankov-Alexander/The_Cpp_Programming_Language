#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;


// 6.3.6.1 The auto Type Specifier
namespace auto_type_specifier {
	int a = 123;
	char a2 = 123;
	auto a3 = 123;  // a3 is int

	template<class T> void f1(vector<T>& arg)
	{
		for (vector<T>::iterator p = arg.begin(); p != arg.end(); ++p)
			*p = 7;

		for (auto p = arg.begin(); p != arg.end; ++p)  // more convenient
			*p = 7;
	}

	void f2(double d)
	{
		const auto max = d + 7;
		int a[max];  // error: array bound not an int
	}

	void f3(vector<int>& v)
	{
		for (const auto& x : v) { /*...*/ }  // x is a const int&
	}

	void g(int& v)
	{
		auto x = v;  // x is an int
		auto& y = v;  // y is an int&
	}
}


// 6.3.6.2 auto and {}-lists
namespace auto_and_init_lists{
	char v1 = 12345;  // 12345 is an int
	int v2 = 'c';  // 'c' is a char
	T v3 = f();

	char v4{ 12345 };  // error: narrowing
	int v5{ 'c' };  // fine: implicit char->int conversion
	T v6{ f() };  // works if the type of f() can be implicitly converted to a T

	auto v7 = 12345;  // int
	auto v8 = 'c';  // char
	auto v9 = f();  // appropriate type

	auto v10{ 12345 };  // initializer_list<int>
	auto v11{ 'c' };  // init list of char
	auto v12{ f() };  // init list of appropriate type

	auto x0{};  // error: cannot deduce the type
	auto x1{ 1 };  // init list of int with one element
	auto x2 = { 1, 2, 3 };  // init list of int with three elements
}


// 6.3.6.3 The decltype() Specifier
namespace decltype_specifier {
	template<class T, class U>
	auto operator+(const Matrix<T>& a, const Matrix<U>& b)->Matrix< decltype(T{} +U{}) > ;

	template<class T, class U>
	auto operator+(const Matrix<T>& a, const Matrix<U>& b)->Matrix<decltype(T{} +U{}) >
	{
		Matrix<decltype(T{} +U{}) > res;
		for (int i = 0; i != a.rows(); ++i)
			for (int j = 0; j != a.columns(); ++j)
				res(i, j) += a(i, j) + b(i, j);
		return res;
	}
}