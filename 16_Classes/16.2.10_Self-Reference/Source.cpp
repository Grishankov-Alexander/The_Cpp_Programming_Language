

class Date {
	int d, m, y;
public:
	Date& add_year(int n);  // add n years
	Date& add_month(int n);
	Date& add_day(int n);
};

Date& Date::add_year(int n)
{
	if (d == 29 && m == 2 && !leapyear(y + n)) {  // beware of February 29
		d = 1; m = 3;
	}
	y += n;
	return *this;
}

void f(Date& d)
{
	d.add_day(1).add_month(1).add_year(1);
}

struct Link {
	Link* pre;
	Link* suc;
	int data;

	Link* insert(int x)  // insert x before this
	{
		return pre = new Link{ pre, this, x };
	}
	void remove()  // remove and destroy this
	{
		if (pre) pre->suc = suc;
		if (suc) suc->pre = pre;
		delete this;
	}
};