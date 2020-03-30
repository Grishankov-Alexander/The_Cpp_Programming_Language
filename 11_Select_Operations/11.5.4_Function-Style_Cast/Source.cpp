void f(double d)
{
	int i = int(d);  // truncate d
	complex z = complex(d);  // make a complex from d
}

void f(double d, char* p)
{
	int a = int(d);
	int b = int(p);  // not portable
}