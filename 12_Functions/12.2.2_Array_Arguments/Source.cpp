int strlen(const char*);
void f()
{
	char v[] = "Annemarie";
	int i = strlen(v);
	int j = strlen("Nicholas");
}

void odd(int* p);
void odd(int a[]);
void odd(int a[2000]);

void f(int(&r)[4]);
void g()
{
	int a1[] = { 1, 2, 3, 4 };
	int a2[] = { 1, 2 };
	f(a1);  // OK
	f(a2);  // error: wrong number of elements
}

template<class T, int N> void f(T(&r)[N]);
int a1[10];
double a2[200];
void g()
{
	f(a1);  // T is int, N is 10
	f(a2);  // T is double, N is 200
}

const char* day[] = {
	"mon", "tue", "wed", "thu", "fri", "sat", "sun"
};