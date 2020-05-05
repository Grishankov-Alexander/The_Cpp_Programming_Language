

int x;
template<typename T>
T f(T a)
{
	++x;  // OK: x is in scope
	++y;  // error: no y in scope
	return a;  // OK: a is dependent
}
int y;
int z = f(2);

void g(double);
void g2(double);
template<typename T>
int ff(T a)
{
	g2(2);  // g2(double)
	g3(2);  // error: no g3 in scope
	g(2);  // g(double)
}
void g(int);
void g3(int);
int x = ff(3);