

class Date {
	int d, m, y;
public:
	explicit Date(int dd = 0, int mm = 0, int yy = 0);
};

explicit Date::Date(int dd, int mm, int yy) { /*...*/ }  // error
Date::Date(int dd, int mm, int yy) : d{ dd }, m{ mm }, y{ yy } { /*...*/ }  // OK

Date d1{ 15 };  // OK: considered explicit
Date d2 = Date{ 10, 2, 2015 };  // OK: explicit
Date d3 = { 15 };  // error: doesn't do implicit conversions
Date d4 = 15;  // error: doesn't do implicit conversions

void my_fct(Date d);
void f()
{
	my_fct(15);  // error: no implicit conversion
	my_fct({ 15 });  // same
	my_fct(Date{ 15 });  // OK: explicit
}