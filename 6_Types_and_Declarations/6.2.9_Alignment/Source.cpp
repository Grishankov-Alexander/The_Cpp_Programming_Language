#include <algorithm>
using namespace std;


auto ac = alignof('c');  // the alignment of a char
auto ai = alignof(1);
auto ad = alignof(1.0);

int a[20];
auto aa = alignof(a);

void user(const vector<X>& vx)
{
	constexpr int bufmax = 1024;
	alignas(X) buffer[bufmax];  // uninitialized

	const int max = min(vx.size(), bufmax / sizeof(X));
	uninitialized_copy(vx.begin(), vx.begin() + max, buffer);
}