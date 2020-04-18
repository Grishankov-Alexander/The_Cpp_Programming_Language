#include <stdexcept>
#include <cstring>
#include <iostream>
#include <cctype>


// 19.3.1 Essential Operations
class String {
public:
	String();  // default constructor
	String(const char* p);  // from c-style string
	String(const String&);
	String& operator=(const String&);
	String(String&&);
	String& operator=(String&&);
	~String() { if (short_max < sz) delete[] ptr; }

	// 19.3.2 Access to Characters
	char& operator[](int n) { return ptr[n]; }  // unchecked element access
	char operator[](int n) const { return ptr[n]; }

	char& at(int n) { check(n); return ptr[n]; }  // range-checked
	char at(int n) const { check(n); return ptr[n]; }

	String& operator+=(char c);  // add c at end

	char* c_str() { return ptr; }
	const char* c_str() const { return ptr; }  // C-style string access

	int size() const { return sz; }  // number of elements
	int capacity() const  // size + available space
	{
		return (sz <= short_max) ? short_max : sz + space;
	}

private:
	// 19.3.3 Representation
	static const int short_max = 15;
	int sz;  // number of characters
	char* ptr;
	union {
		int space;  // unused allocated space
		char ch[short_max + 1];  // leave space for terminating 0
	};
	
	void check(int n) const  // range check
	{
		if (n < 0 || sz <= n)
			throw std::out_of_range{ "String::at()" };
	}

	// ancillary member functions
	void copy_from(const String& x);
	void move_from(String& x);
};

// 19.3.3.1 Ancillary Functions
char* expand(const char* src, int n)  // expand into free store
{
	char* dest = new char[n];
	std::strcpy(dest, src);
	return dest;
}

void String::copy_from(const String& x)
// make *this a copy of x
{
	if (x.sz <= short_max) {
		memcpy(this, &x, sizeof(x));
		ptr = ch;
	}
	else {
		ptr = expand(x.ptr, x.sz + 1);
		sz = x.sz;
		space = 0;
	}
}

void String::move_from(String& x)
{
	if (x.sz <= short_max) {
		memcpy(this, &x, sizeof(x));
		ptr = ch;
	}
	else {
		ptr = x.ptr;
		sz = x.sz;
		space = x.space;
		x.ptr = x.ch;  // x = ""
		x.sz = 0;
		x.ch[0] = 0;
	}
}

// 19.3.4 Member Functions
String::String()
	: sz{ 0 }, ptr{ ch } { ch[0] = 0; }

String::String(const char* p)
	: sz{ strlen(p) },
	ptr{ (short_max >= sz) ? ch : new char[sz + 1] },
	space{ 0 }
{
	strcpy(ptr, p);
}

String::String(const String& x)
{
	copy_from(x);
}

String& String::operator=(const String& x)
{
	if (this == &x) return *this;
	char* p = (short_max < sz) ? ptr : 0;
	copy_from(x);
	delete[] p;
	return *this;
}

String::String(String&& x)
{
	move_from(x);
}

String& String::operator=(String&& x)
{
	if (this == &x) return *this;
	if (short_max < sz) delete[] ptr;
	move_from(x);
	return *this;
}

String& String::operator+=(char c)
{
	if (sz == short_max) {
		int n = 2*sz + 2;  // double the size
		ptr = expand(ptr, n);
		space = n - sz - 2;
	}
	else if (short_max < sz) {
		if (space == 0) {
			int n = 2 * sz + 2;
			char* p = expand(ptr, n);
			delete[] ptr;
			ptr = p;
			space = n - sz - 2;
		}
		else
			--space;
	}
	ptr[sz] = c;
	ptr[++sz] = 0;
	return *this;
}

// 19.3.5 Helper Functions
std::ostream& operator<<(std::ostream& os, const String& s)
{
	return os << s.c_str();
}

std::istream& operator>>(std::istream& is, String& s)
{
	s = String{ "" };  // clear the target string
	is >> std::ws;  // skip whitespace
	char ch;
	while (is.get(ch) && !std::isspace(ch))
		s += ch;
	return is;
}

bool operator==(const String& a, const String& b)
{
	if (a.size() != b.size()) return false;
	for (int i = 0; i != a.size(); ++i)
		if (a[i] != b[i]) return false;
	return true;
}

bool operator!=(const String& a, const String& b)
{
	return !(a == b);
}

char* begin(String& x)
{
	return x.c_str();
}

const char* begin(const String& x)
{
	return x.c_str();
}

char* end(String& x)
{
	return x.c_str() + x.size();
}

const char* end(const String& x)
{
	return x.c_str() + x.size();
}

String& operator+=(String& a, const String& b)
{
	for (auto x : b) a += b;
	return a;
}

String operator+(const String& a, const String& b)
{
	String res{ a };
	res += b;
	return res;
}

String operator""_s(const char* p, size_t)
{
	return String{ p };
}


// 19.3.2 Access to Characters
int hash(const String& s)
{
	int hash{ s[0] };
	for (int i{ 1 }; i != s.size(); ++i)  // unchecked access to s
		hash ^= s[i] >> 1;
}
