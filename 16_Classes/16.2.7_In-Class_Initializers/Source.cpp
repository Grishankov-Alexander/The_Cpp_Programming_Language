
class Date {
	int d{ today.d };
	int m{ today.m };
	int y{ today.y };
public:
	Date(int, int, int);
	Date(int);
};

Date::Date(int dd) : d{ dd } { /*...*/ }  // == d{ dd }, m{ today.m }, y{ today.y }
