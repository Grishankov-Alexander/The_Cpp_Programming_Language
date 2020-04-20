#include <string>
#include <list>
using namespace std;


struct Employee {
	string first_name, family_name;
	char middle_initial;
	short department;
};

struct Manager : public Employee {
	list<Employee*> group;
	short level;
};

void f(Manager mm, Employee ee)
{
	list<Employee*> elist{ &mm, &ee };  // OK
	Employee* pe = &mm;  // OK
	Manager* pm = &ee;  // error
	pm->level = 2;  // disaster, ee doesn't have a level
	pm = static_cast<Manager*>(pe);  // brute force but OK
	pm->level = 2;  // fine: pm points to the manager mm
}
