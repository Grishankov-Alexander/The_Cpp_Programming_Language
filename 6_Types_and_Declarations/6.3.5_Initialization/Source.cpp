#include <vector>
#include <string>
#include <complex>
#include <list>
#include <iostream>
using namespace std;


// 6.3.5 Initialization
namespace Initialization {
	X a1{ v };
	X a2 = { v };
	X a3 = v;
	X a4(v);

	void f(double val, int val2)
	{
		int x2 = val;  // if val==7.9, x2 becomes 7
		char c2 = val2;  // if val2==1025, c2 becomes 1
		int x3{ val };  // error: possible truncation
		char c3{ val2 };  // error: possible narrowing
		char c4{ 24 };  // OK: 24 can be represented exactly as char
		int c5{ 264 };  // error (assuming 8-bit chars): 264 cannot be represented as char
		int x4{ 2.0 };  // error: no double to int value conversion
	}

	auto z1{ 99 };  // z1 is an initializer_list<int>
	auto z2 = 99;  // z2 is an int

	vector<int> v1{ 99 };  // v1 is a vector of 1 element with the value 99
	vector<int> v2(99);  // v2 is a vector of 99 elements each with the default value 0
	vector<string> v3{ "hello!" };  // v3 is a vector of 1 element with the value "hello!"
	vector<string> v4("hello!");  // error: no vector constructor takes a string literal

	int x4{};  // x4 becomes 0
	double d4{};  // d4 becomes 0.0
	char* p{};  // p becomes nullptr
	vector<int> v5{};  // v5 becomes the empty vector
	string s4{};  // s4 becomes ""
}


// 6.3.5.1 Missing Initializers
namespace missing_initializers {
	int a;  // means "int a{};" so that a becomes 0
	double d;  // means "double d{};" so that d becomes 0.0
	constexpr int max = 1024;
	char buf[max];  // initialize every char to 0
	
	void f1()
	{
		char buf[max];  // uninitialized
		cin.get(buf, max);  // read at most max characters into buf
	}

	void f2()
	{
		int x;  // x does not have a well-defined value
		char buf[1024];  // buf[i] does not have a well-defined value
		int* p{ new int };  // uninitialized
		char* q{ new char[1024] };  // same
		string s;  // s=="" because of string's default constructor
		vector<char> v;  // v=={} because of vector's default constructor
		string* ps{ new string };  // *ps is ""
	}

	void ff()
	{
		int x{};   // x becomes 0
		char buff[1024]{};  // buf[i] is 0 for all i
		int* p{ new int{ 10 } };  // *p becomes 10
		char* q{ new char[1024]{} };  // q[i] becomes 0 for all i
	}
}


// 6.3.5.2 Initializer Lists
namespace initializer_lists {
	int a[] = { 1, 2 };  // array initializer
	struct S { int x; string s; };
	S s = { 2, "Helios" };  // struct initializer
	vector<double> v = { 0.0, 1.1, 2.2, 3.3 };  // use list constructor

	complex<double> z(0, pi);  // use constructor
	vector<double> v2(10, 3.3);  // use constructor: v gets 10 elements initialized to 3.3

	complex<double> f1();  // function declaration
	complex<double> f2{};  // init by constructor to the default value {0, 0}

	auto x1 = { 1.0, 2.0, 3.0 };  // x1 is an initializer_list<double>
	auto x2 = { 1.0, 2 };  // error: cannot deduce the type
}