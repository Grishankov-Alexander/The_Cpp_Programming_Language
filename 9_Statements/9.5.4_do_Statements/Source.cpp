void print_backwards(char a[], int i)  // i must be positive
{
	cout << '{';
	do {
		cout << a[--i];
	} while (i);
	cout << '}';
}