#include <list>
#include <string>
#include <iostream>
using namespace std;


// 4.4.2 list
namespace lst {
	
	// std::list is a double-linked list.
	// 1. it is good for insertions and deletions of elements
	// without moving other elements
	// 2. elements should be accessed by range-for loops or iterations
	// 3. A vector performs better for traversal (find() and count()).
	// 4. A vector performs better for sorting and searching (sort(), binary_search())

	list<Entry> phone_book = {
		{"David Hume", 123456},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
	};

	int get_number(const string& s)
	{
		for (const auto& e : phone_book)
			if (e.name == s)
				return e.number;
		return 0;  // use 0 to represent "number not found"
	}

	int get_number2(const string& s)
	{
		for (auto p = phone_book.begin(); p != phone_book.end(); ++p)
			if (p->name == s)
				return p->number;
		return 0;
	}

	// adding and removing elements
	void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
	{
		phone_book.insert(p, ee);  // add ee before the element referred to by p
		phone_book.erase(q);  // remove the element referred to by q
	}
}