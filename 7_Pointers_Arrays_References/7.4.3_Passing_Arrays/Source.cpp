#include <iostream>
using namespace std;


void comp(double arg[10])  // arg is double*
{
	for (int i = 0; i != 10; ++i)
		arg[i] += 99;
}
void comp(double* arg)
{
	for (int i = 0; i != 10; ++i)
		arg[i] += 99;
}

void f()
{
	double a1[10];
	double a2[5];
	double a3[100];
	comp(a1);
	comp(a2);  // disaster!
	comp(a3);  // uses only the first 10 elements
}

void print_m35(int m[3][5])
{
	for (int i = 0; i != 3; i++) {
		for (int j = 0; j != 5; j++)
			cout << m[i][j] << '\t';
		cout << endl;
	}
}

void print_mi5(int m[][5], int dim1)
{
	for (int i = 0; i != dim1; i++) {
		for (int j = 0; j != 5; j++)
			cout << m[i][j] << '\t';
		cout << endl;
	}
}

/*
void print_mij(int m[][], int dim1, int dim2)  // doesn't behave as most people would thing
{
	for (int i = 0; i != dim1; i++) {
		for (int j = 0; j != dim2; j++)
			cout << m[i][j] << '\t';  // surprise
		cout << endl;
	}
}
*/

void print_mij(int* m, int dim1, int dim2)
{
	for (int i = 0; i != dim1; i++) {
		for (int j = 0; j != dim2; j++)
			cout << m[i*dim2 + j] << '\t';  // obscure
		cout << endl;
	}
}

int test()
{
	int v[3][5] = {
		{ 0, 1, 2, 3, 4 }, { 10, 11, 12, 13, 14 }, { 20, 21, 22, 23, 24 }
	};
	print_m35(v);
	print_mi5(v, 3);
	print_mij(&v[0][0], 3, 5);
}