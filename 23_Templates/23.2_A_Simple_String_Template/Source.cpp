#include <map>
#include <iostream>


template<typename C>
class String {
public:
	String();
	explicit String(const C*);

	String(const String&);
	String& operator=(const String&);

	C& operator[](int n) { return ptr[n]; }  // unchecked element access
	String& operator+=(C c);  // add c at end
private:
	static const int short_max = 15;  // short string optimization
	int sz;
	C* ptr;  // ptr points to C arr[sz]
};

String<char> cs;
String<unsigned char> us;
struct Jchar {};  // japanese character
String<Jchar> js;


// 23.2.1 Defining a Template
template<typename C>
String<C>::String()
	: sz{ 0 }, ptr{ ch }
{
	ch[0] = {};  // terminating 0 of the appropriate type
}

template<typename C>
String<C>& String<C>::operator+=(C c)
{
	//  add c to the end
	return *this;
}
