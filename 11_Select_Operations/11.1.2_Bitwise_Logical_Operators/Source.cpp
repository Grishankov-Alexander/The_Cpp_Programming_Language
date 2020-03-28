#include <iostream>
using namespace std;

/*
enum iostate {
	goodbit = 0, eofbit = 1, failbit = 2, badbit = 4
};
iostate state = goodbit;
// ...
if (state & (failbit | badbit))  // stream not good
state |= eofbit;

int old = cin.rdstate();  // returns the state
// ... use cin ...
if (cin.rdstate() ^ old) {  // has anything changed ?
	// ...
}
*/

constexpr unsigned short middle(int a)
{
	static_assert(sizeof(int) == 4, "unexpected int size");
	static_assert(sizeof(short) == 2, "unexpected short size");
	return (a >> 8) & 0xFFFF;
}
constexpr int x = 0xFF00FF00;  // assume sizeof(int) == 4
constexpr unsigned short y = middle(x);  // y = 0x00FF