#include <vector>
#include <iostream>
#include <string>
using namespace std;


// 4.4.1 vector
namespace vec {
	// initialize with a set of values
	vector<Entry> phone_book = {
		{"David Hume", 123456},
		{"Karl Popper", 234567},
		{"Bertrand Arthur William Russell", 345678}
	};

	// accessing elements
	void print_book(const vector<Entry>& book)
	{
		for (int i = 0; i != book.size(); ++i)
			cout << book[i] << '\n';
	}

	void print_book2(const vector<Entry>& book)
	{
		for (const auto& e : book)
			cout << e << '\n';
	}

	// definitions
	vector<int> v1 = { 1, 2, 3, 4 };  // size is 4
	vector<string> v2;  // size is 0
	vector<Shape*> v3(43);  // size is 23; initial element value: nullptr
	vector<double> v4(32, 9.9);  // size is 32, initial element value: 9.9

	// add new element to the end (efficient)
	void input()
	{
		for (Entry e; cin >> e;)
			phone_book.push_back(e);
	}

	// copying:
	vector<Entry> book2 = phone_book;
}


// 4.4.1.2 Range Checking
namespace range_checking {
	// std::vector doesn't guarantee range checking
	void silly(vector<Entry>& book)
	{
		int i = book[ph.size()].number;  // book.size() is out of range
		// ...
	}

	// range-checking adaptation of vector
	template<typename T>
	class Vec : public vector<T> {
	public:
		using vector<T>::vector;  // use the constructors from vector (under the name Vec)
		T& operator[](int i)  // range check
		{
			return vector<T>::at(i);
		}
		const T& operator[](int i) const  // range check const objects;
		{
			return vector<T>::at(i);
		}
	};

	void checked(Vec<Entry>& book)
	{
		try {
			book[book.size()] = { "Joe", 99999 };  // will throw an exception
		}
		catch (out_of_range) {
			cout << "range error\n";
		}
	}

	int main()
	{
		try {
			// your code
		}
		catch (out_of_range) {
			cerr << "range error\n";
		}
		catch (...) {
			cerr << "unknown exception thrown\n";
		}
	}
}