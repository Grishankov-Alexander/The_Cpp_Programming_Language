#include <type_traits>
using namespace std;


struct substitution_failure {};  // represent a failure to declare something

template<typename T>
struct substitution_succeeded : true_type {};  // value = true
template<>
struct substitution_succeeded<substitution_failure> : false_type {};

template<typename T>
struct get_f_result {
private:
	template<typename X>
	static auto check(const X & x) -> decltype(f(x));  // can call f(x)
	static substitution_failure check(...);  // cannot call f(x)
public:
	using type = decltype(check(declval<T>()));
};

template<typename T>
struct has_f
	: substitution_succeeded<typename get_f_result<T>::type>
{};

template<typename T>
constexpr bool Has_f() { return has_f<T>::value; }

template<bool B, class T = void>
using Enable_if = typename enable_if<B, T>::type;


template<typename T>
class X {
	// if there exists f(T), declare void use_f(T& t);
	Enable_if<Has_f<T>()> use_f(T& t) { f(t); }
};

template<typename Iter, typename Val>
Enable_if<Has_not_equals<Iter>(), Iter> find(Iter first, Iter last, Val v)
{
	while (first != last && !(*first == v)) ++first;
	return first;
}

template<typename T>
auto operator!=(const T& a, const T& b) -> decltype(!(a == b))
{
	return !(a == b);
}