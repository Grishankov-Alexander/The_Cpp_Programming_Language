#include <string>
using namespace std;


class Ptr {
public:
	X* operator->();
};
void f(Ptr p)
{
	p->m = 7;  // X*->m = 7
	X* q1 = p->;  // syntax error
	X* q2 = p.operator->();  // OK
}

template<typename T>
class Disk_ptr {
	string identifier;
	T* in_core_address;
public:
	Disk_ptr(const string& s) : identifier{ s }, in_core_address{ nullptr } {}
	~Disk_ptr() { write_to_disk(in_core_address, identifier); }

	T* operator->()
	{
		if (in_core_address == nullptr)
			in_core_address = read_from_disk(identifier);
		return in_core_address;
	}
};

struct Record {
	string name;
};

void update(const string& s)
{
	Disk_ptr<Record> p{ s };
	p->name = "Roscoe";  // update s; if necessary, first retreive from disk
}  // p's destructor writes back to disk

template<typename T>
class Ptr {
	T* p;
public:
	T* operator->() { return p; }  // dereference to access member
	T& operator*() { return *p; }  // dereference to access whole object
	T& operator[](int i) { return p[i]; }  // dereference to access element
};