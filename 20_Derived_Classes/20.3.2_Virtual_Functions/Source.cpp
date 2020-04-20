#include <list>
#include <string>
#include <iostream>
using namespace std;


class Employee {  // run-time polymorphic type
public:
	Employee(const string& name, short dept);
	virtual void print() const;
private:
	string family_name;
	short department;
};

void Employee::print() const
{
	cout << family_name << '\t' << department << '\n';
}

class Manager : public Employee {
public:
	Manager(const string& name, short dept, short lvl);
	void print() const;
private:
	list<Employee*> group;
	short level;
};

void Manager::print() const
{
	Employee::print();
	cout << "\tLevel: " << level << '\n';
}

void print_list(const list<Employee*>& elist)
{
	for (auto x : elist)
		x->print();  // run-time polymorphism
}

int main()
{
	Employee e{ "Brown", 123 };
	Manager m{ "Smith", 122, 3 };
	print_list({ &m, &e });
}