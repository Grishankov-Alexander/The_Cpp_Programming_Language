#include <iostream>
#include <string>
#include <cstdio>
using namespace std;


#define NAME rest of line
named = NAME  // named = rest of line

#define MAC(x, y) argument1: x argument2: y
expanded = MAC(foo bar, yuk yuk)  // expanded = argument1: foo bar argument2: yuk yuk

#define PRINT(a, b) cout << (a) << (b)
#define PRINT(a, b, c) cout << (a) << (b) << (c) /* trouble?: redefines, does not overload */
#define FAC(n) (n > 1) ? (n * FAC(n - 1)) : (1)  /* trouble: recursive macro */

#define CASE break;case
#define FOREVER for(;;)

#define SQUARE(a) a*a
#define INCR_xx (xx)++
int xx = 0;  // global counter
void f(int xx)
{
	int y = SQUARE(xx);  // y = xx * xx
	int y2 = SQUARE(xx + 2);  // y = xx + 2 * xx + 2
	INCR_xx;  // increments argument xx (not the global xx)
}

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
int x = 1;
int y = 10;
int z = MIN(x++, y++);  // x becomes 3; y becomes 11

#define M2(a) something(a)  /* thoughtful comment */
#define NAME2(a, b) a##b
int NAME2(hack, cah)();  // int hackcah()

#define PRINTX(x) cout << #x " = " << x << '\n';
int a = 7;
string str = "asdf";
void f()
{
	PRINTX(a);  // cout << "a" << " = " << a << '\n';
	PRINTX(str);  // cout << "str" << " = " << str << "\n";
}
#undef PRINTX

#define EMPTY() std::cout << "empty\n"
EMPTY();  // print "empty\n"
EMPTY;  // error: macro replacement list missing

#define err_print(...) fprintf(stderr, "error: %s %d\n", __VA_ARGS__)
err_print("The answer", 54);  // error: The answer 54\n