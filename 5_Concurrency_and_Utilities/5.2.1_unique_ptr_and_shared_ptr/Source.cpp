#include <memory>
#include <fstream>
using namespace std;


// unique_ptr ensures that its object is properly destroyed whichever way we exit f()
void f(int i, int j)  // X* vs. unique_ptr<X>
{
	X* p = new X;  // allocate a new X
	unique_ptr<X> sp{ new X };  // allocate a new X and give its pointer to unique_ptr
	// ...
	if (i < 99) throw Z{};  // may throw an exception
	if (j < 77) return;  // may return "early"
	p->do_something();  // may throw an exception
	sp->do_something();
	// ...
	delete p;  // destroy *p
}

unique_ptr<X> make_X(int i)
	// make an X and immediately give it to a unique_ptr
{
	// ... checki, etc.
	return unique_ptr<X>{ new X{ i } };
}

// The shared_ptrs for an object share ownership of an object and that object is destroyed
// when the last of its shared_ptrs is destroyed.
void f(shared_ptr<fstream>);
void g(shared_ptr<fstream>);

void user(const string& name, ios_base::openmode mode)
{
	shared_ptr<fstream> fp{ new fstream(name, mode) };
	// make sure the file was properly opened
	if (!*fp) throw runtime_error{ "No file" };

	f(fp);
	g(fp);
	// ...
}