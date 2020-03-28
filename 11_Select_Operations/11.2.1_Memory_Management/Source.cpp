#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

void f1()  // leaks
{
	int* p1 = new int{ 99 };
	int* p2 = p1;  // potential trouble
	delete p1;  // now p2 doesn't point to a valid object
	p1 = nullptr;  // gives a false sense of safety
	char* p3 = new char{ 'x' };  // p3 may point to the memory pointed to by p2
	*p2 = 999;  // this may cause trouble
	cout << *p3 << '\n';  // may not print 'x'
}

void sloppy()  // double deletion
{
	int* p = new int[1000];  // acquire memory
	// ... use *p ...
	delete[] p;  // release memory
	// ... wait a while ...
	delete[] p;  // but sloppy() does not own *p
}

void f(const string& s)
{
	vector<char> v;
	for (auto c : s)
		v.push_back(c);
}

Token_stream ts{ new istringstream{ "some string" } };

void f(int n)
{
	int* p1 = new int[n];  // potential trouble
	unique_ptr<int[]> p2{ new int[n] };
	if (n % 2) throw runtime_error{ "odd" };
	delete[] p1;  // we may never get here
}