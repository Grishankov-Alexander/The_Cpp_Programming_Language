#include <algorithm>

namespace Estd {
	using namespace std;

	template<class C>
	void sort(C& c)
	{
		sort(c.begin(), c.end());
	}

	template<class C, class Pred>
	void sort(C& c, Pred p)
	{
		sort(c.begin(), c.end(), p);
	}
}