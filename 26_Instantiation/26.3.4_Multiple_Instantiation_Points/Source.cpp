

void f(int) { return; }

namespace N {
	class X {};
	char g(X, int) { return 'a'; }
}

template<typename T>
auto ff(T t, double d) -> decltype(g(t, d))
{
	f(d);  // binds to f(int)
	return g(t, d);  // might be bound to g(X, int)
}

auto x1 = ff(N::X{}, 1.1);  // may bind g to N::g(X, int)

namespace N {  // reopen N and overload g
	double g(X, double) { return 3.3; }
}

auto x2 = ff(N::X{}, 2.2);

int main()
{

}