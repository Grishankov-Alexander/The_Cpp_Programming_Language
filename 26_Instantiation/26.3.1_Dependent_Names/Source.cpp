
/*
template<typename T>
T f(T a)
{
	return g(a);  // OK: a is dependent name, therefore so is g
}
class Quad {};
int g(Quad q);
int z = f(Quad{});  // f's g is bound to g(Quad)

template<typename T>
T ff(T a)
{
	return gg(Quad{});  // error no gg() in scope and gg(Quad{}) doesn't depend on T
}
int gg(Quad);
int zz = ff(Quad{});

template<typename Iter>
using Value_type = typename Iter::value_type;

template<typename Container>
void fct(Container& c)
{
	typename Container::value_type v1 = c[9];  // OK: value_type assumed to name a type
	auto v2 = c[7];  // OK: let the compiler figure it out
	Value_type<Container> v3 = c[11];  // OK
}
*/
class Pool {  // some allocator
public:
	template<typename T> T* get();
	template<typename T> void release(T*);
};

template<typename Alloc>
void f(Alloc& alloc)
{
	int* p1 = alloc.get<int>();  // syntax error: get is assumed to name non-template
	int* p2 = alloc.template get<int>();  // OK: get() is assumed to be a template
}

void user(Pool& pool)
{
	f(pool);
}

int main()
{
	Pool pool{};
	user(pool);
}