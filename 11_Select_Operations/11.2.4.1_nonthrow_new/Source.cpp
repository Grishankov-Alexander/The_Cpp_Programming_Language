#include <new>
using namespace std;


void f(int n)
{
	int* p = new(nothrow) int[n];  // allocate n ints on the free store
	if (!p) {  // no memory available
		// ... handle allocation error
	}
	delete(nothrow, p);  // deallocates *p
}

// allocate sz bytes; return nullptr if allocation failed
void* operator new(size_t sz, const nothrow_t&) noexcept;
// deallocate space allocated by new
void operator delete(void* p, const nothrow_t&) noexcept;
void* operator new[](size_t sz, const nothrow_t&) noexcept;
void operator delete[](void* p, const nothrow_t&) noexcept;