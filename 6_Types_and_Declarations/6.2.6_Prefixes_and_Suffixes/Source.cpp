

// Notation			*fix		Meaning				Example
// 0				prefix		octal				0776
// 0x	0X			prefix		hexadecimal			0Xff
// u	U			suffix		unsigned			10U
// l	L			suffix		long				20000L
// ll	LL			suffix		long long			20000LL
// f	F			suffix		float				10f
// e	E			infix		floating-point		10e-4
// .				infix		floating-point		12.3
// ------------------------------------------------------
// '				prefix		char				'c'
// u'				prefix		char16_t			u'c'
// U'				prefix		char32_t			U'c'
// L'				prefix		wchar_t				L'c'
// ------------------------------------------------------
// "				prefix		string				"mess"
// R"				prefix		raw string			R"(\b)"
// u8"	u8R"		prefix		UTF-8 string		u8"foo"
// u"	uR"			prefix		UTF-16 string		u"foo"
// U"	UR"			prefix		UTF-32 string		U"foo"
// L"	LR"			prefix		wchar_t string		L"foo"

// int forms
int i = 12;  // decimal
unsigned int ui = 014;  // octal
signed int si = 0xC;
// int sizes
short s = 0XFF;  // short int
long l = 1333333;  // long int
long long ll1 = 022LL;  // long long int
unsigned long ul1 = 1LU;
unsigned long ul2 = 1UL;
unsigned long long ull1 = 1ull;
signed long long sll = 0x22LL;

double d = 12.13e-4;  // double precision
long double ld = 123.123L;  // extended precision
float f = 122.13f;  // single precision