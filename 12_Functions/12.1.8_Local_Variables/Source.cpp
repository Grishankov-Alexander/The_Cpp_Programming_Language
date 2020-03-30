#include <iostream>

void f(int a)
{
	while (a--) {
		static int n = 0;  // initialized once
		int x = 0;  // initialized 'a' times in each call of f()
		std::cout << "n == " << n++ << ", x == " << x++ << "\n";
	}
}

int fn(int n)
{
	static int n1 = n;  // OK
	static int n2 = fn(n - 1) + 1;  // undefined
	return n;
}

int main(int argc, char* argv[])
{
	f(12);
	fn(10);
}