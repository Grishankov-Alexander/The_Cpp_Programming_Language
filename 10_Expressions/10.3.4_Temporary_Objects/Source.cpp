#include <string>
#include <iostream>
using namespace std;


void f(string& s1, string& s2, string& s3)
{
	const char* cs = (s1 + s2).c_str();  // possible pointer to destroyed object
	cout << cs;
	if (strlen(cs = (s2 + s3).c_str()) < 8 && cs[0] == 'a') {
		// cs may point to destroyed temp obj
	}
}

void f2(string& s1, string& s2, string& s3)
{
	cout << s1 + s2;
	string s = s2 + s3;
	if (s.length() < 8 && s[0] == 'a') {
		// use s here
	}
}

void g(const string&, const string&);
void h(string& s1, string& s2)
{
	const string& s = s1 + s2;
	string ss = s1 + s2;
	g(s, ss);  // we can use s and ss here
}

void f3(Shape& s, int n, char ch)
{
	s.move(string{ n, ch });  // construct a string with n copies of ch to pass to Shape::move()
}