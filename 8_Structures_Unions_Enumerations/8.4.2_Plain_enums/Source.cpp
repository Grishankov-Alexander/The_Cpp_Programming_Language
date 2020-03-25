

enum Traffic_light { red, yellow, green };
enum Warning { green, yellow, orange, red };  // fire alert levels
// error: two definitions of yellow (to the same value)
// error: two definitions of red and green (to different values)

Warning a1 = 7;  // error: no int->Warning conversion
int a2 = green;  // OK: green is in scope and converts to int
int a3 = Warning::green;  // Ok: Warning->int conversion
Warning a4 = Warning::green;  // OK

void f(Traffic_light x)
{
	if (x == 9) { /*...*/ }  // ok (but traffic_light doesn't have a 9)
	if (x == red) { /*...*/ }  // error: two reds in scope
	if (x == Warning::red) { /*...*/ }  // OK (Ouch!)
	if (x == Traffic_light::red) { /*...*/ }  // OK
}

enum Traffic_light { tl_red, tl_yellow, tl_green };
void f(Traffic_light x)
{
	if (x == red) { /*...*/ }  // Ok (ouch!)
	if (x == Warning::red) { /*...*/ }  // OK (ouch!)
	if (x == Traffic_light::red) { /*...*/ }  // error: red is not a Traffic_light value
}

enum Traffic_light : char { tl_red, tl_yellow, tl_green };  // underlying type is char
enum Color_code : char;  // declaration
void foobar(Color_code* p);  // use of declaration
enum Color_code : char { red, yellow, green, blue };  // definition

enum E1 { dark, light };  // range 0:1
enum E2 { a = 3, b = 9 };  // range 0:15
enum E3 { min = -10, max = 1000000 };  // range -1048576:1048575

enum Flag { x = 1, y = 2, z = 4, e = 8 };  // range 0:15
Flag f0{};  // f0 gets the default value 0
Flag f1 = 5;  // error: 5 is not of type Flag
Flag f2 = Flag{ 5 };  // error: no explicit conversion from int to Flag
Flag f2 = static_cast<Flag>(5);  // OK: 5 is within the range of Flag
Flag f3 = static_cast<Flag>(z | e);  // OK: 12 is within the range of Flag
Flag f4 = static_cast<Flag>(99);  // undefined: 99 is not within the range of Flag
