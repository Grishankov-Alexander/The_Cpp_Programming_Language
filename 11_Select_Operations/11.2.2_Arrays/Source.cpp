#include <string>
#include <vector>
using namespace std;


char* save_string(const char* p)
{
	char* s = new char[strlen(p) + 1];
	strcpy(s, p);
	return s;
}

string save_string2(const char* p)
{
	return string{ p };
}

void f(int n)
{
	vector<int>* p = new vector<int>(n);  // individual object
	int* q = new int[n];  // array
	// ...
	delete p;
	delete[] q;
}

int main(int argc, char* argv[])
{
	if (argc < 2) exit(1);
	char* p = save_string(argv[1]);
	// ...
	delete[] p;
}