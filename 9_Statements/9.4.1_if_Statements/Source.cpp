enum E1 { a, b };
enum class E2 { a, b };
void f(E1 x, E2 y)
{
	if (x) { /*...*/ }  // OK
	if (y) { /*...*/ }  // error: no conversion to bool
	if (y == E2::a) { /*...*/ }  // OK
}

int max(int a, int b)
{
	return (a > b) ? a : b;  // return the larger of a and b
}

void f2(int i)
{
	if (i) {
		int x = i + 2;
		++x;
	}
	else {
		++x;  // error: x is not in scope
	}
	++x;  // error: x is not in scope
}

void f1(int i)
{
	if (i)
		int x = i + 2;  // error: declaration of if-statement branch
}