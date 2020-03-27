void f(int x, int y)
{
	int j = x = y;  // the value of x=y is the value of x after the assignment
	int* p = &++x;  // p points to x
	int* q = &(x++);  // error: x++ is not an lvalue (it is not the value stored in x)
	int* p2 = &(x > y ? x : y);  // address of the int with the larger value
	int& r = (x < y) ? x : 1;  // error: 1 is not an lvalue
}

void f()
{
	int i = 1;
	while (0 < i) ++i;
	cout << "i has become negative!" << i << '\n';
}