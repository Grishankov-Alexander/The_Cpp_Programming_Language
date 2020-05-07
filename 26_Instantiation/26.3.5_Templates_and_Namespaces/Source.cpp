
namespace N {
	class A {};
	char f(A);
}

char f(int);

template<typename T>
char g(T t)
{
	return f(t);  // choose f() depending on what T is
}

char f(double);

char c1 = g(N::A{});  // N::f(N::A) will be called
char c2 = g(2);  // f(int)
char c3 = g(5.3);  // f(int)