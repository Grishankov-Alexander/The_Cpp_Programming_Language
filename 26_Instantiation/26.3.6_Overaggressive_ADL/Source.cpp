
#include <vector>
#include <algorithm>


namespace User {
	class Customer {};
	using Index = std::vector<Customer*>;
	void copy(const Index&, Index&, int deep);  // deep or shallow
	void algo(Index& x, Index& y)
	{
		copy(x, y, false);  // std::copy
		copy(x, y, 1);  // User::copy
		User::copy(x, y, false);  // OK
	}
}
