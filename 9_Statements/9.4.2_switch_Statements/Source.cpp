#include <iostream>
#include <string>
using namespace std;


// 9.4.2 switch Statements
namespace switch_statements {
	void f(int i)
	{
		switch (i) {
		case 2.7:  // error: float used for case
			// ...
		case 2:  // OK
			// ...
		case 4 - 2:  // 2 already used
			// ...
		}
	}

	void f1(int val) {
		switch (val) {  // beware
		case 1:
			cout << "case 1\n";
		case 2:
			cout << "case 2\n";
		default:
			cout << "default: case not found\n";
		}
	}

	switch (action) {  // handle (action, value) pair
	case do_and_print:
		act(value);
		// no break: fall through to print
	case print:
		print(value);
		break;
	}
	
	enum class Vessel { cup, glass, goblet, chalice };
	void problematic(Vessel v)
	{
		switch (v) {
		case Vessel::cup: /*...*/ break;
		case Vessel::glass: /*...*/ break;
		case Vessel::goblet: /*...*/ break;
		}
	}
}


// 9.4.2.1 Declarations in Cases
namespace declarations_in_cases {
	void f(int i)
	{
		switch (i) {
		case 0:
			int x;  // uninitialized
			int y = 3;  // error: declaration can be bypassed (explicitly initialized)
			string s;  // error: declaration can be bypassed (implicitly initialized)
		case 1:
			++x;  // error: use of uninitialized object
			++y;
			s = "nasty";
		}
	}
}