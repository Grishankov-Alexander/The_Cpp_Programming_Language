
template<int N>
constexpr bool Small_size()
{
	return N <= 8;
}

constexpr int stack_limit = 2048;
template<typename T> constexpr bool Is_regular() { return true; }
template<typename T, int N>
constexpr bool Is_stackable()  // T is Regular and N elements of T can fit on stack
{
	return Is_regular<T>() && sizeof(T) * N <= stack_limit;
}

template<typename T, int N>
struct Buffer {};

template<typename T, int N>
void fct()
{
	static_assert(Is_stackable<T, N>(), "fct(): Buffer is too small");
}

int main()
{ constexpr auto s = sizeof(int);
fct<int, 512>();  // OK
fct<int, 513>();  // static_assert failure
}