#include <utility>
#include <memory>
#include <string>



template<typename T, typename U>
void f(const T*, U(*)(U));
int g(int);
void h(const char* p)
{
	f(p, g);  // T is char, U is int
	f(p, h);  // can't deduce U
}

template<typename T>
void fct(T i, T* p);

void g(int i)
{
	fct(i, &i);  //OK
	fct(i, "Remember!");  // error: ambiguous
}


// 23.5.2.1 Reference Deduction
namespace reference_deduction {
	template<typename T>
	class Xref {
	public:
		Xref(int i, T* p)  // store a pointer, Xref is the owner
			: index{ i }, elem{ p }, owner{ true }
		{}
		Xref(int i, T& r)  // store a pointer ot r, owned elsewhere
			: index{ i }, elem{ &r }, owner{ false }
		{}
		Xref(int i, T&& r)  // move r into Xref, Xref is the owner
			: index{ i }, elem{ new T{ std::move(r) } }, owner{ true }
		{}
		~Xref() { if (owner) delete elem; }
	private:
		bool owner;
		T* elem;
		int index;
	};

	std::string x{ "There and back again" };
	Xref<std::string> r1{ 7, "Here" };  // Xref(int i, T&& r)
	Xref<std::string> r2{ 9, x };  // Xref(int i, T&)
	Xref<std::string> r3{ 3, new std::string{ "There" } };  // Xref(int i, T* p)

	template<typename T, typename A>
	std::unique_ptr<T> make_unique(int i, A&& a)
	{
		return std::unique_ptr<T>{ new T{ i, std::forward<A>(a) } };
	}
}

int main(int argc, char* argv[])
{
	using namespace reference_deduction;
	auto p1 = make_unique<Xref<std::string>>(7, "Here");
}