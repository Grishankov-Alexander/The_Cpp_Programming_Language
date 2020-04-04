#include <cstdio>
#include <stdexcept>
#include <mutex>
#include <string>
using namespace std;


void use_file(const char* fn)  // clumsy code
{
	FILE* f = fopen(fn, "r");
	try {
		// use f
	}
	catch (...) {
		fclose(f);
		throw;
	}
	fclose(f);
}

class File_ptr {
	FILE* p;
public:
	File_ptr(const char* n, const char* a)  // open file n
		: p{ fopen(n, a) }
	{
		if (!p) throw runtime_error{ "File_ptr: nullptr" };
	}
	File_ptr(const string& n, const char* a)
		: File_ptr{ n.c_str(), a }
	{}
	explicit File_ptr(FILE* pp)  // assume ownership of pp
		: p{ pp }
	{
		if (!p) throw runtime_error{ "File_ptr: nullptr" };
	}
	~File_ptr() { fclose(p); }
	operator FILE* () { return p; }
};
void use_file(const char* fn)
{
	File_ptr f(fn, "r");
	// ... use f
}

class Locked_file_handle {
	File_ptr p;
	unique_lock<mutex> lck;
public:
	Locked_file_handle(const char* file, mutex& m)
		: p{ file, "rw" },  // acquire file
		lck{ m }  // acquire mutex
	{}
};