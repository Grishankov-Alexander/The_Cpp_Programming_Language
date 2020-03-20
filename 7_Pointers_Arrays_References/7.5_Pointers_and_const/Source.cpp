const int model = 90;  // model is a const
const int v[] = { 1, 2, 3, 4 };  // v[i] is a const
const int x;  // error: no initializer

void f()
{
	model = 200;  // error
	v[3] = 5;  // error
}

void g(const int* p)
{
	// can't modify *p here
}

void h()
{
	int val;  // val can be modified here
	g(&val);
	// ...
}

void f1(char* p)
{
	char s[] = "Gorm";

	const char* pc = s;  // pointer to constant
	pc[3] = 'g';  // error: pc points to constant
	pc = p;  // OK

	char* const cp = s;  // constant pointer
	cp[3] = 'a';  // OK
	cp = p;  // error: cp is constant

	const char* const cpc = s;  // const pointer to const
	cpc[3] = 'a';  // error: cpc points to constant
	cpc = p;  // error: cpc is constant
}

char* const cp;  // const pointer to char
const char* pc;  // pointer to const char
char const* pc2;  // pointer to const char

const char* strchr(const char* p, char c);  // find first occurrence of c in p
char* strchr(char* p, char c);  // find first occurrence of c in mutable p

void f4()
{
	int a = 1;
	const int c = 2;
	const int* p1 = &c;  // OK
	const int* p2 = &a;  // OK
	int* p3 = &c;  // error: initialization of int* with const int*
	*p3 = 7;  // try to change the value of c
}