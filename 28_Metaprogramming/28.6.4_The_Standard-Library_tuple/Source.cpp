#include <type_traits>
#include <iostream>


template<class... Tail> class tuple {};

template<class Head, class... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
	typedef tuple<Tail...> inherited;
public:
	constexpr tuple(const Head& v = Head{}, const Tail&... vtail) : m_head(v), inherited(vtail...) {}
	template<class... VValues>
	tuple(const tuple<VValues...>& other)
		: m_head{ other.head() }, inherited(other.tail()) {}
	template<class... VValues>
	tuple& operator=(const tuple<VValues...>& other)
	{
		m_head = other.head();
		tail() = other.tail();
		return *this;
	}
	Head& head() { return m_head; }
protected:
	Head m_head;
private:
	
	const Head& head() const { return m_head; }
	inherited& tail() { return *this; }
	const inherited& tail() const { return *this; }
};


template<typename... Types>
tuple<Types...> make_tuple(Types&&... t)
{
	return tuple<Types...>{t...};
}

template<size_t N> // print element N and following elements
struct print_tuple {
	template<class... T>
	static std::enable_if_t<(N < sizeof...(T))>
		print(std::ostream& os, tuple<T...>& t)
	{
		os << ", " << std::get<N>(t);
		print_tuple<N + 1>::print(os, t);
	}
	template<class... T>
	static std::enable_if_t<!(N < sizeof...(T))>
		print(std::ostream&, tuple<T...>&) {}
};

std::ostream& operator<<(std::ostream& os, const tuple<>&)
{
	return os << "{}";
}
template<class T0, class... Ts>
std::ostream& operator<<(std::ostream& os, const tuple<T0, Ts...>& t)
{
	os << "{ " << std::get<0>(t);
	os << print_tuple<1>::print(os, t);
	return os << " }";
}

void user()
{
	int i = 9;
	std::cout << make_tuple(i, 2.2) << '\n';
}


int main()
{
	constexpr tuple<int, double> t{ 3, 2.2 };
	user();
}