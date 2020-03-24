#include <string>
using namespace std;


class Entry2 {  // two alternative representations represented as union
private:
	enum  class Tag { number, text };
	Tag type;  // discriminant
	union {
		int i;
		string s;  // string has default constructor, copy operations and destructor
	};
public:
	struct Bad_entry {};  // used for exceptions
	string name;

	~Entry2();
	Entry2& operator=(const Entry2&);  // necessary because of the string variant
	Entry2(const Entry2&);
	// ...

	int number() const;
	void set_number(int n);
	string text() const;
	void set_text(const string&);
};

int Entry2::number() const
{
	if (type != Tag::number) throw Bad_entry{};
	return i;
}

string Entry2::text() const
{
	if (type != Tag::text) throw Bad_entry{};
	return s;
}

void Entry2::set_number(int n)
{
	if (type == Tag::text) {
		s.~string();  // explicitly destroy string
		type = Tag::number;
	}
	i = n;
}

void Entry2::set_text(const string& ss)
{
	if (type == Tag::text) s = ss;
	else {
		new(&s) string{ ss };  // placement new: explicitly construct string
		type = Tag::text;
	}
}

Entry2& Entry2::operator=(const Entry2& e)  // necessary because of the string variant
{
	if (type == Tag::text && e.type == Tag::text) {
		s = e.s;  // usual string assignment
		return *this;
	}
	if (type == Tag::text) s.~string();  // explicit destroy
	switch (e.type) {
	case Tag::number:
		i = e.i;
		type = e.type;
		break;
	case Tag::text:
		new(&s) string{ e.s };  // placement new: explicit construct
		type = e.type;
		break;
	}
	return *this;
}

Entry2::~Entry2()
{
	if (type == Tag::text) s.~string();  // explicit destroy
}