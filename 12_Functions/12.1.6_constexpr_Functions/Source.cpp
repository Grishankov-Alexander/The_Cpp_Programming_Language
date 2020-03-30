constexpr int fac(int n)
{
	return (n > 1) ? n * fac(n - 1) : 1;
}

constexpr int f9 = fac(9);  // must be evaluated at compile time
void f(int n)
{
	int f5 = fac(5);  // may be evaluated at compile time
	int fn = fac(n);  // evaluated at run time
	constexpr int f6 = fac(6);  // must be evaluated at compile time
	constexpr int fnn = fac(n);  // error: can't guarantee compile-time evaluation
	char a[fac(4)];  // OK: array bounds must be constants
	char a2[fac(n)];  // error
}

int glob;
constexpr void bad1(int a)  // error: constexpr function can not be void
{
	glob = a;  // error: side effect in constexpr function
}
constexpr int bad2(int a)
{
	if (a >= 0) return a; else return -a;  // error: if-statement in constexpr function
}
constexpr int bad3(int a)
{
	int sum = 0;  // error: local variable in constexpr
	for (int i = 0; i < a; ++i) sum += fac(i);  // error: loop in constexpr
	return sum;
}