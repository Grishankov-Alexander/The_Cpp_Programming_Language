#include <string>
#include <vector>
#include <iostream>
using namespace std;


namespace Chrono {
	
	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	class Date {
	public:  // interface
		class Bad_date {};  // exception class
		explicit Date(
			int dd = {}, Month mm = {}, int yy = {}
		);  // {} means "pick default"

		int day() const;
		Month month() const;
		int year() const;
		string string_rep() const;  // string representation
		void char_rep(char s[], int max) const;  // C-style representation

		Date& add_day(int n);
		Date& add_month(int n);
		Date& add_year(int n);

	private:
		int d; Month m; int y;
		bool is_valid();
	};

	bool is_leapyear(int y);
	bool is_date(int d, Month m, int y);
	
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& d);

	const Date& default_date();
}


// 16.3.1 Member Functions
namespace Chrono {
	Date::Date(int dd, Month mm, int yy)
		: d{ dd }, m{ mm }, y{ yy }
	{
		if (y == 0) y = default_date().year();
		if (m == Month{}) m = default_date().month();
		if (d == 0) d = default_date().day();
		if (!is_valid()) throw Bad_date{};
	}

	bool Date::is_valid()
	{
		return is_date(d, m, y);
	}

	inline int Date::day() const
	{
		return d;
	}

	Date& Date::add_month(int n)
	{
		if (n == 0) return *this;
		else if (n > 0) {
			int delta_y = n / 12;  // number of whole years
			int mm = static_cast<int>(m) + n % 12;  // number of months ahead
			if (mm > 12) {
				++delta_y; mm -= 12;
			}
			// ... handle the cases where the month mm doesn't have day d
			y += delta_y;
			m = static_cast<Month>(mm);
			return *this;
		}
		// ... handle negative n
		return *this;
	}
}

void fill(vector<Chrono::Date>& aa)
{
	while (cin) {
		Chrono::Date d;
		try {
			cin >> d;
		}
		catch (Chrono::Date::Bad_date) {
			// error handlling
			continue;
		}
		aa.push_back(d);
	}
}


// 16.3.2 Helper Functions
namespace Chrono {
	bool is_date(int d, Month m, int y)
	{
		int ndays;
		switch (m) {
		case Month::feb:
			ndays = 28 + is_leapyear(y);
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			ndays = 30;
			break;
		case Month::jan: case Month::mar: case Month::may: case Month::jul:
		case Month::aug: case Month::oct: case Month::dec:
			ndays = 31;
			break;
		default:
			return false;
		}
		return 1 <= d && d <= ndays;
	}

	const Date& default_date()
	{
		static Date d{ 1, Month::jan, 1970 };
		return d;
	}
}