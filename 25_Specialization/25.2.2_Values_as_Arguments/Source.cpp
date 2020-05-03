

template<typename T, int max>
class Buffer {
	T v[max];
public:
	Buffer() {}
	Buffer(int i) { max = i; }  // error: attempt to assign to template value argument
};

Buffer<char, 128> cbuf;
Buffer<int, 5000> ibuf;

constexpr int max = 200;
void f(int i)
{
	Buffer<int, i> bx;  // error: constexpr expected
	Buffer<int, max> bm;  // OK
}

template<typename T, char* label>
class X {};

X<int, "BMW323Ci"> x1;  // error: string literal as template argument
char lx2[] = "BMW323Ci";
X<int, lx2> x2;  // OK, lx2 has external linkage

template<typename T, T default_value = T{}>
class Vec {};

Vec<int, 23> c1;
Vec<int> c11;  // default_value is int{}
Vec<char> c22;