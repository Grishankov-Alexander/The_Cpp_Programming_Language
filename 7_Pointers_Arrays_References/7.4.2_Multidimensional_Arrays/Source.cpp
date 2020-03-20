#include <iostream>
using namespace std;


int ma[3][5];  // 3 arrays with 5 ints each

void init_ma()
{
	for (int i = 0; i != 3; i++)
		for (int j = 0; j != 5; j++)
			ma[i][j] = 10 * i + j;
}

void print_ma()
{
	for (int i = 0; i != 3; i++) {
		for (int j = 0; j != 5; j++)
			cout << ma[i][j] << '\t';
		cout << endl;
	}
}

int bad[3, 5];  // error: comma not allowed in constexpr
int good[3][5];
int ouch = good[1, 4];  // error: int initialized by int* (good[1,4] means good[4], which is an int*)
int nice = good[1][4];