void confused(int* p)
{
	// delete p?
}

int global{ 7 };

void f()
{
	int* pn = new int{ 7 };
	int i{ 7 };
	int* q = &i;
	confused(pn);
	confused(q);
	confused(&global);
}