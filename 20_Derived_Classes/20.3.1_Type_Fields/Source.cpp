#include <string>
#include <list>
#include <iostream>
using namespace std;


struct Employee {
	Employee() : type{ empl } {}

	enum Empl_type { empl, man };
	Empl_type type;
	string first_name, family_name;
	short department;
};

struct Manager : public Employee {
	Manager() { type = man; }
	
	list<Employee*> group;  // people managed
	short level;
};

void print_employee(const Employee* e)
{
	switch (e->type) {
	case Employee::empl:
		cout << e->first_name << " " << e->family_name
			<< e->department << "\n";
		break;
	case Employee::man:
	{
		cout << e->family_name << '\t' << e->department << '\n';
		const Manager* m{ static_cast<const Manager*>(e) };
		cout << "level: " << m->level << '\n';
		break;
	}
	}
}

void print_list(const list<Employee*>& elist)
{
	for (auto x : elist)
		print_employee(x);
}