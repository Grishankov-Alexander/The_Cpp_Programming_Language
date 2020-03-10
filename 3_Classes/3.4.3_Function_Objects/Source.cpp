#include <iostream>
#include <string>
#include <vector>
#include <list>


template<typename T>
class Less_than {
	const T val;  // value to compare against
public:
	Less_than(const T& v) : val(v) {}
	bool operator()(const T& x) { return x < val; }  // call operator
};

Less_than<int> lti{ 42 };  // lti(i) will compare i to 42 (i<42)
Less_than<std::string> lts{ "Backus" };  // lts(s) will compare s < "Backus"

void fct(int n, const std::string& s)
{
	bool b1 = lti(n);  // true if n < 42
	bool b2 = lts(s);  // true if s < "Backus"
}

// function objects are widely used as arguments to algorithms
template<typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for (const auto& x : c)
		if (pred(x))
			++cnt;
	return cnt;
}

void f(
	const std::vector<int>& vec,
	const std::list<std::string>& lst,
	int x, const std::string& s
) {
	std::cout << "Number of values less than " << x
		<< ": " << count(vec, Less_than<int>{ x }) << '\n';
	std::cout << "Number of values less than " << s
		<< ": " << count(lst, Less_than<std::string>{ s }) << '\n';
}


// lambda expressions
namespace lambda_expressions {
	void f(const std::vector<int>& vec,
		const std::list<std::string>& lst,
		int x, const std::string& s)
	{
		std::cout << "Number of values less than " << x
			<< ": " << count(vec, [&](int a) { return a < x; })
			<< '\n';
		// [&] is a capture list specifying that local names (x)
		// will be passed by reference.
		// [=] is to pass by value. [=x] is to capture only x by value
		// [&x] is to capture only x by reference.
		// [] - capture nothing
		std::cout << "Number of values less than " << s
			<< ": " << count(lst, [&](const std::string& a) { return a < s; })
			<< '\n';
	}

	template<class C, class Oper>
	void for_all(C& c, Oper op)  // assume that C is a container of pointers
	{
		for (auto& x : c)
			op(*x);  // pass op() a reference to each element pointed to
	}

	// a new version of user() from 3.2.4
	void user()
	{
		std::vector<std::unique_ptr<Shape>> v;
		while (std::cin)
			v.push_back(read_shape(std::cin));
		for_all(v, [](Shape& s) { s.draw(); });  // draw_all()
		for_all(v, [](Shape& s) { s.rotate(45); });  // rotate_all(45)
	}
}
