#include <type_traits>
#include <iostream>
#include <stdexcept>

// 28.6.1 A Type-Safe printf()
namespace tsprintf {
	void printf(const char* s);
	template<class T, class... Args>
	void printf(const char* s, T value, Args... args);
}

void tsprintf::printf(const char* s)
{
	while (s && *s) {
		if (*s == '%' && *++s != '%')  // make sure no more arguments are expected
			throw std::runtime_error{ "invalid format: missing arguments" };
		std::cout << *s++;
	}
}

template<class T, class... Args>  // variadic template argument list: one or more arguments
void tsprintf::printf(const char* s, T value, Args... args)  // function argument list: two or more args
{
	while (s && *s) {
		if (*s == '%') {  // a format specifier or %%
			switch (*++s) {
			case '%':
				break;
			case 's':
				// check if T is const char* or std::string
				break;
			case 'd':
				if (!std::is_integral_v<T>)
					throw std::runtime_error{ "printf(): bad format" };
				break;
			case 'g':
				if (!std::is_floating_point_v<T>)
					throw std::runtime_error{ "printf(): bad format" };
				break;
			}
			std::cout << value;  // use first non-format argument
			return printf(++s, args...);  // do a recursive call with the tail of the argument list
		}
		std::cout << *s++;
	}
	throw std::runtime_error{ "printf(): too much arguments" };
}


int main()
{
	using tsprintf::printf;
	printf("Hello %s %d %g", "world!", 133, 24.44);
}