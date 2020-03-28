struct S { int a, b; };
struct SS { double a, b; };
void f(S);
void g(S);
void g(SS);
void h()
{
	f({ 1, 2 });
	g({ 1, 2 });  // error: ambiguous
	g(S{ 1, 2 });
	g(SS{ 1, 2 });
}
