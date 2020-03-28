#include <string>
using namespace std;


void cpy(char* p, const char* q)
{
	while (*p++ = *q++);
}

void cpy1(char* p, const char* q)
{
	int length = strlen(q);
	for (int i = 0; i <= length; i++)
		p[i] = q[i];
}

void cpy2(char* p, const char* q)
{
	int i;
	for (i = 0; q[i] != 0; i++)
	{
		p[i] = q[i];
	}
	p[i] = 0;  // terminating zero
}

void cpy3(char* p, const char* q)
{
	while (*q != 0) {
		*p = *q;
		p++;
		q++;
	}
	*p = 0;  // terminating zero
}