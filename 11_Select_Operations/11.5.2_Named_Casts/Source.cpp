IO_device* d1 = reinterpret_cast<IO_device*>(0xff00);  // device at 0xff00

void* my_allocator(size_t);
void f()
{
	int* = static_cast<int*>(my_allocator(100));  // new allocation used as ints
}

char x{ 'a' };
int* p1 = &x;  // error: no implicit char* to int* conversion
int* p2 = static_cast<int*>(&x);  // error: no implicit char* to int* conversion
int* p3 = reinterpret_cast<int*>(&x);  // OK: on your head be it

struct B {};
struct D : B {};
B* pb = new D;  // OK: implicit conversion from D* to B*
D* pd = pb;  // error: no implicit conv from B* to D*
D* pd = static_cast<D*>(pb);  // OK
