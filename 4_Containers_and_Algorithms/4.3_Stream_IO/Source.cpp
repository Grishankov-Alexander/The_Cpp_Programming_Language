#include <iostream>
#include <string>
using namespace std;


// 4.3.1 Output
namespace output {
	
	void f()
	{
		cout << 10;
	}

	void g()
	{
		int i{ 10 };
		cout << i;
	}

	void h(int i)
	{
		cout << "\nthe value of i is ";
		cout << i;
		cout << '\n';
	}

	void h2(int i)
	{
		cout << "the value of i is " << i << '\n';
	}

	void k()
	{
		int b = 'b';  // note: char implicitly converted to int
		char c = 'c';
		cout << 'a' << b << c;
	}
}

// 4.3.2 Input
namespace input {

	void f()
	{
		int i;
		cin >> i;  // read an integer into i
		double d;
		cin >> d;  // read a double-precision floating-point number into d
	}

	void hello()
	{
		cout << "Please enter your name\n";
		string str;
		cin >> str;  // whitespace terminates the read
		cout << "Hello, " << str << "!\n";
	}

	void hello_line()
	{
		cout << "Please enter your name\n";
		string str;
		getline(cin, str);  // read whitespaces
		cout << "Hello, " << str << "!\n";
	}
}

// 4.3.3 I/O of User-Defined Types
namespace user_defined_io {

	struct Entry {
		string name;
		int number;
	};

	ostream& operator<<(ostream& os, const Entry& e)
	{
		return os << "{\"" << e.name << "\", " << e.number << "}";
	}

	istream& operator>>(istream& is, Entry& e)
		// read {"name", number} pair to Entry (cin >> Entry)
		// Note: when used as condition, "is >> c" means
		// "Did we succeed at reading from is into c?".
		// Note 2: is >> c skips whitespaces. is.get(c) doesn't
	{
		char c, c2;
		if (is >> c && c == '{' && is >> c2 && c2 == '"') {  // if starts with a {"
			string name;  // the default value of a string is the empty string: ""
			while (is.get(c) && c != '"')
				name += c;
			if (is >> c && c == ',') {
				int number = 0;
				if (is >> number >> c && c == '}') {  // read the number and a }
					e = { name, number };  // assign to the entry
					return is;
				}
			}
		}
		is.setf(ios_base::failbit);  // register the failure in the stream
		return is;
	}
}


int main()
{
	cout << "Type your phone entries like this: {\"name\", number}\n";
	using namespace user_defined_io;
	for (Entry ee; cin >> ee;)  // read from cin into ee
		cout << "Your entry is: " << ee << '\n';  // write ee to cout
	return 0;
}