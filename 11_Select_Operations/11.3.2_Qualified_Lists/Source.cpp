struct S { int a, b; };
void f()
{
	S v{ 7, 8 };  // direct initialization of a variable
	v = S{ 7, 8 };  // assign using qualified list
	S* p = new S{ 7, 8 };  // construct on the free store using qualified list
}

template<class T>
T square(T x)
{
	return x * x;
}
void f(int i)
{
	double d = square(double{ i });
	complex<double> z = square(complex<double>{ i });
}