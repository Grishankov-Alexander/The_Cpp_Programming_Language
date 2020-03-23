#include <iostream>
using namespace std;


struct Address {
	const char* name;  // "Jim Dandy"
	int number;  // 61
	const char* street;  // "South St"
	const char* town;  // "New Providence"
	char state[2];  // 'N', 'J'
	const char* zip;  // "07974"
};

void f()
{
	Address jd1;
	jd1.name = "Jim Dandy";
	jd1.number = 61;

	Address jd2 = {
		"Jim Dandy", 61, "South St",
		"New Providence", { 'N', 'J' }, "07974"
	};
}

void print_addr(Address* p)
{
	cout << p->name << '\n'
		<< p->number << ' ' << p->street << '\n'
		<< p->town << '\n' << p->state[0] << p->state[1]
		<< ' ' << p->zip << '\n';
}

void print_addr2(const Address& r)
{
	cout << r.name << '\n' << r.number << ' '
		<< r.street << '\n' << r.town << '\n'
		<< r.state[0] << r.state[1] << ' ' << r.zip << '\n';
}

Address current;
Address set_current(Address next)
{
	Address prev = current;
	current = next;
	return prev;
}