#include <iostream>

template<typename T>
struct Link {
	Link* pre;
	Link* suc;
	T val;
};

template<typename T>
class List {
public:
	List(Link<T>* link = nullptr) : head{ link } {}
	List(const T& t) : head{ new Link<T>{ nullptr, nullptr, t } } {}
	
	void print_all() const;
private:
	Link<T>* head;
};

template<typename T>
void List<T>::print_all() const
{
	for (Link<T>* p = head; p; p = p->suc)
		std::cout << *p;
}
