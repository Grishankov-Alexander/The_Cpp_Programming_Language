#include <memory>

template<typename T, typename D = std::default_delete<T>>
class unique_ptr {
public:
	explicit operator bool() const noexcept;  // does *this hold a valid pointer ?
};

void use(unique_ptr<int> p, unique_ptr<char> q)
{
	if (!p)  // OK: we want this use
		throw Invalid_unique_ptr{};
	bool b = p;  // error: suspicious use
	int x = p + q;  // error: we definitely don't want this
}