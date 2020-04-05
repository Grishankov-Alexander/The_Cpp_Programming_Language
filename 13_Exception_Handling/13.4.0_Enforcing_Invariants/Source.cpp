#include <cassert>
#include <stdexcept>
#include <string>
#include <sstream>
#include <exception>
using namespace std;


void f(int n)
// n should be in [1:max)
{
	if (n <= 0 || n >= max)
		throw Assert_error("range problem");
}

namespace Assert {
	enum class Mode { throw_, terminate_, ignore_ };
	constexpr Mode current_mode = CURRENT_MODE;
	constexpr int current_level = CURRENT_LEVEL;
	constexpr int default_level = 1;
	constexpr bool level(int n) { return n <= current_level; }
	struct Error : runtime_error {
		Error(const string& m) : runtime_error{ m } {}
	};
	string compose(const char* file, int line, const string& message)
		// compose message including file name and line number
	{
		ostringstream os("(");
		os << file << "," << line << "): " << message << '\n';
		return os.str();
	}

	template<bool condition = level(default_level), class Except = Error>
	void dynamic(bool assertion, const string& message = "Assert::dynamic failed")
	{
		if (assertion) return;
		if (current_mode == Mode::throw_) throw Except{ message };
		if (current_mode == Mode::terminate_) terminate();
	}
	template<>
	void dynamic<false, Error>(bool, const string&) {}  // do nothing
	void dynamic(bool b, const string& s)  // default action
	{
		dynamic<true, Error>(b, s);
	}
	void dynamic(bool b)  // default message
	{
		dynamic<true, Error>(b);
	}
}


void f(int n)
{
	Assert::dynamic<Assert::level(2), Assert::Error>(
		(1 <= n && n < max), Assert::compose(__FILE__, __LINE__, "range problem");
	);
	Assert::dynamic((1 <= n && n < max), Assert::compose(__FILE__, __LINE__, "range problem"));
	using namespace Assert;
	dynamic(1 <= n && n < max);
}