int v[] = { 1, 2, 3, 4 };
int* p1 = v;  // pointer to initial element (implicit conversion)
int* p2 = &v[0];  // pointer to initial element
int* p3 = v + 4;  // pointer to one-beyond last element

int* p4 = v - 1;  // before the beginning, undefined: don't do it
int* p5 = v + 7;  // beyond the end, undefined

extern "C" int strlen(const char*);  // from <string.h>
void f()
{
	char v[] = "Annemarie";
	char* p = v;  // implicit conversion of char[] to char*
	strlen(p);
	strlen(v);  // implicit conversion from char[] to char*
	v = p;  // error: cannot assign to array
}