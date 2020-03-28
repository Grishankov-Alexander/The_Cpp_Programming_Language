class X {
public:
	X(int a);
	~X();
};

void* operator new(size_t, void* p) { return p; }  // explicit placement operator
void* buf = reinterpret_cast<void*>(0xF00F);  // significant address
X* p2 = new(buf) X(2);  // construct an X at buf; invoke: operator new(sizeof(X), buf)

class Arena {
public:
	virtual void* alloc(size_t) = 0;
	virtual void free(void*) = 0;
};

void* operator new(size_t sz, Arena* a)
{
	return a->alloc(sz);
}

extern Arena* Persistent;
extern Arena* Shared;

void g(int i)
{
	X* p = new(Persistent) X(i);  // X in persistent storage
	X* q = new(Shared) X(i);  // X in shared memory
}

void destroy(X* p, Arena* a)
{
	p->~X();  // call destructor
	a->free(p);  // free memory
}