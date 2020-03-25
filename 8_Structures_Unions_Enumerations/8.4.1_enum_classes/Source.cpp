

enum class Traffic_light { red, yellow, green };
enum class Warning { green, yellow, orange, red };  // fire alert levels

Warning a1 = 7;  // error: no int->Warning conversion
int a2 = green;  // error: green not in scope
int a3 = Warning::green;  // error: no Warning->int conversion
Warning a4 = Warning::green;  // OK

void f(Traffic_light x)
{
	if (x == 9) { /*...*/ }  // error: 9 is not a Traffic_light
	if (x == red) { /*...*/ }  // error: no red in scope
	if (x == Warning::red) { /*...*/ }  // error: x is not a Warning
	if (x == Traffic_light::red) { /*...*/ }  // OK
}

enum class Warning : char { green, yellow, orange, red };  // sizeof(Warning)==1
enum class Warning : int { green, yellow, orange, red };  // sizeof(Warning)==sizeof(int)

bool b1 = static_cast<int>(Warning::green) == 0;
bool b2 = static_cast<int>(Warning::yellow) == 1;
bool b3 = static_cast<int>(Warning::orange) == 2;
bool b4 = static_cast<int>(Warning::red) == 3;

void f(Warning key)
{
	switch (key) {
	case Warning::green:
		// do something
		break;
	case Warning::orange:
		// do something
		break;
	case Warning::red:
		// do smth
		break;
	}
}

enum class Printer_flags {
	acknowledge = 1,
	paper_empty = 2,
	busy = 4,
	out_of_black = 8,
	out_of_color = 16,
	// ...
};

constexpr Printer_flags operator|(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a) | static_cast<int>(b));
}
constexpr Printer_flags operator&(Printer_flags a, Printer_flags b)
{
	return static_cast<Printer_flags>(static_cast<int>(a)& static_cast<int>(b));
}

void try_to_print(Printer_flags x)
{
	if (x & Printer_flags::acknowledge) {
		// ...
	}
	else if (x & Printer_flags::busy) {
		// ...
	}
	else if (x & (Printer_flags::out_of_black | Printer_flags::out_of_color)) {
		// either we are out of black or we are out of color
		// ...
	}
}

void g(Printer_flags x)
{
	switch (x) {
	case Printer_flags::acknowledge:
		// ...
		break;
	case Printer_flags::busy:
		// ...
		break;
	case Printer_flags::out_of_black:
		// ...
		break;
	case Printer_flags::out_of_color:
		// ...
		break;
	case Printer_flags::out_of_black& Printer_flags::out_of_color:
		// we are out of black *and* out of color
		// ...
		break;
	}
}

enum class Color_code : char;  // declaration
void foobar(Color_code* p);  // use of declaration
// ...
enum class Color_code : char { red, yellow, green, blue };  // definition

enum class Flag : char { x = 1, y = 2, z = 4, e = 8 };
Flag f0{};  // f0 gets the default value 0
Flag f1 = 5;  // type error: 5 is not of type Flag
Flag f2 = Flag{ 5 };  // error: no narrowing conversion to an enum class
Flag f3 = static_cast<Flag>(5);  // brute force
Flag f4 = static_cast<Flag>(999);  // error: 999 is not a char value (maybe not caught)
int i = static_cast<int>(Flag::y);  // i becomes 2
char c = static_cast<char>(Flag::e);  // c becomes 8
