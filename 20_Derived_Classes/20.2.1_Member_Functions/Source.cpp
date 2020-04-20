#include <string>
#include <iostream>
using namespace std;


class Employee {
public:
	void print() const;
	string full_name() const
	{
		return first_name + ' ' + middle_initial + ' '
			+ family_name;
	}
private:
	string first_name, family_name;
	char middle_initial;
};

class Manager : public Employee {
public:
	void print() const;
};

void Manager::print() const
{
	cout << full_name() << '\n';  // OK
	cout << family_name << '\n';  // error: can't access base's private member
	Employee::print();  // call base's print
}