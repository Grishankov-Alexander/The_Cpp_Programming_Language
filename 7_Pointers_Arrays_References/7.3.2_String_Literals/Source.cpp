#include <iostream>
#include <string>
using namespace std;


// 7.3.2 String Literals
namespace string_literals {
	bool b = sizeof("Bohr") == 5;
	void f()
	{
		char* p1 = "Plato";  // error, but accepted in pre-C++11 standard code
		const char* p2 = "Plato";
		p2[4] == 'e';  // error: assignment to const
	}

	void f2()
	{
		char p[] = "Zeno";  // p is an array of 5 char
		p[0] = 'R';  // OK
	}

	const char* error_message(int i)
	{
		// ...
		return "range error";
	}

	const char* p = "Heraclitus";
	const char* q = "Heraclitus";
	void g()
	{
		if (p == q) cout << "one!\n";  // the result is implementation-defined
		cout << "beep at end of message\a\n";
		char alpha[] = "abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	}
}


// 7.3.2.1 Raw Character Strings
namespace raw_character_strings {
	string s1 = "\\w\\\\w";
	string s2 = R"(\w\\w)";
	string s3 = R"("quoted string")";  // "quoted string"
	// "quoted string containing the usual terminator("))"
	string s4 = R"***("quoted string containing the usual terminator("))")***";
	string s5{ R"(1
22
333)" };  // "1\n22\n333"
}


// 7.3.2.2 Larger Character Sets
namespace larger_char_sets {
	const wchar_t s1[] = L"angst";  // wide chars
	const wchar_t s2[] = LR"(angst)";  // raw wide chars
	const char s3[] = "folder\\file";  // implementation character set string
	const char s4[] = R"(folder\file)";  // implementation character raw set string
	const char s5[] = u8"foldef\\file";  // UTF-8 string
	const char* s6 = u8R"(folder\file)";  // UTF-8 raw string
	const char16_t* s7 = u"folder\\file";  // UTF-16 string
	const char16_t* s8 = uR"(folder\file)";  // UTF-16 raw string
	const char32_t* s9 = U"folder\\file";  // UTF-32 string
	const char32_t* s10 = UR"(folder\file)";  // UTF-32 raw string
	const char* s11 = u8"The official vowels in Danish are: a, e, i, "
		"o, u, \u00E6, \u00F8, \u00e5 and y";

}