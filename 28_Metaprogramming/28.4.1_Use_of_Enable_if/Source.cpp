#include  <type_traits>
using namespace std;

template<bool B, typename T>
using Enable_if = typename enable_if<B, T>::type;

template<typename Iter>
constexpr bool Input_iterator() { return false; }

template<typename T>
class vector {
public:
	vector(size_t n, const T& val);
	template<class Iter, class = Enable_if<Input_iterator<Iter>(), Iter>>
	vector(Iter b, Iter e);
};

vector<double> v(10, 20);

Enable_if<true, double>* make_default()  // error: not a template
{
	return new double;
}

template<typename T>
void f(const T& x)
{
	Enable_if<(sizeof(T) < 20), T> tmp{ x };  // error: tmp is not a function
	Enable_if<!(sizeof(T) < 20), T&> tmp2{};
}