#include <string>
#include <utility>
using namespace std;


template<typename T, int max>
class Buffer {
	T buf[max];
	friend T& lookup<T, max>(Buffer& b, const char* p);
};

template<typename T, int max>
T& lookup(Buffer<T, max>& b, const char* p);

string& f(Buffer<string, 128>& buf, const char* p)
{
	return lookup(buf, p);
}

template<typename T1, typename T2>
pair<T1, T2> make_pair(T1 a, T2 b)
{
	return { a, b };
}
auto x = make_pair(7, 7);  // pair<int, int>

template<typename T>
T* create();  // make a T and return a pointer to it
void f()
{
	int* p = create<int>();
	int* q = create();  // can't deduce
}