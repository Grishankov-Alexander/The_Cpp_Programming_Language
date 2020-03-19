#include <iostream>
using namespace std;


void fi(char v[])
{
	for (int i = 0; v[i] != 0; ++i)
		use(v[i]);
}
void fp(char v[])
{
	for (char* p = v; *p != 0; ++p)
		use(*p);
}

a[j] == *(&a[0] + j) == *(a + j) == *(j + a) == j[a];  // 3["Texas"]=="Texas"[3]=='a'

template<typename T>
int byte_diff(T* p, T* q)
{
	return reinterpret_cast<char*>(q) - reinterpret_cast<char*>(p);
}

void diff_test()
{
	int vi[10];
	short vs[10];
	cout << vi << ' ' << &vi[1] << ' ' << &vi[1] - &vi[0] << ' ' << byte_diff(&vi[0], &vi[1]) << '\n';
	cout << vs << ' ' << &vs[1] << ' ' << &vs[1] - &vs[0] << ' ' << byte_diff(vs, vs + 1) << '\n';
	// will produce something like this:
	// 0093F9F8 0093F9FC 1 4
	// 0093F9DC 0093F9DE 1 2
}

void f()
{
	int v1[10];
	int v2[10];
	int i1 = &v1[5] - &v1[3];  // i1 = 2
	int i2 = &v1[5] - &v2[3];  // result undefined
	int* p1 = v2 + 2;  // &v2[2]
	int* p2 = v2 - 2;  // undefined
}

void fp2(char v[], int size)
{
	for (int i = 0; i != size; ++i)
		use(v[i]);  // hope that v has at least size elements
	for (int x : v)
		use(x);  // error: range-for does not work for pointers
	const int N = 7;
	char v2[N];
	for (int i = 0; i != N; ++i)
		use(v2[i]);
	for (int x : v2)
		use(x);  // range-for works for arrays of known size
}