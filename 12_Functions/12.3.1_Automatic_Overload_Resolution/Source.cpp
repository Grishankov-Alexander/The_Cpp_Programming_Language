void print(int);
void print(char);
void print(long);
void print(double);
void print(const char*);

void h(char c, int i, short s, float f)
{
	print(1L);  // print(long)
	print(1.0);  // print(double)
	print(c);  // exact match: print(char)
	print(i);  // exact match: print(int)
	print(s);  // integral promotion: print(int)
	print(f);  // to double promotion: print(double)
	print('a');  // print(char)
	print(49);  // print(int)
	print(0);   // print(int)
	print(nullptr);  // nullptr_t to const char* promotion
}