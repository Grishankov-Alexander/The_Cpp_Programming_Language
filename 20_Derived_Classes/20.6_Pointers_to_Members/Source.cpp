#include <map>
#include <string>
#include <iostream>
using namespace std;


// 20.6.1 Pointers to Function Members
class Std_interface {
public:
	virtual void start() = 0;
	virtual void suspend() = 0;
	virtual ~Std_interface() {};
};

using Pstd_mem = void (Std_interface::*)();  // pointer-to-member type

void f(Std_interface* p)
{
	Pstd_mem s = &Std_interface::suspend;  // pointer to suspend()
	p->suspend();  // direct call
	(p->*s)();  // call through pointer to member
}

map<string, Std_interface*> variable;
map<string, Pstd_mem> operation;

void call_member(string var, string oper)
{
	(variable[var]->*operation[oper])();  // var.oper()
}

class Task {
public:
	static void schedule();
};
void (Task::* pm)() = &Task::schedule;  // error: &Task::schedule is ordinary pointer
void (*pm)() = &Task::schedule;  // OK


// 20.6.2 Pointers to Data Members
struct C {
	const char* val;
	int i;

	void print(int x) { cout << val << x << '\n'; }
	int f1(int);
	void f2();
	C(const char* v) : val{ v } {}
};

using Ptmf = void (C::*)(int);  // pointer to member function of C taking an int
using Pm = const char* C::*;  // pointer to const char* data member of C
using Pim = int C::*;  // pointer to int member

void f(C& z1, C& z2)
{
	C* p = &z2;
	Ptmf pf = &C::print;
	Pm pm = &C::val;

	z1.print(1);
	(z1.*pf)(2);
	z1.*pm = "nv1 ";
	p->*pm = "nv2 ";
	z2.print(3);
	(p->*pf)(4);

	pf = &C::f1;  // error: return type mismatch
	pf = &C::f2;  // error: argument type mismatch
	pm = &C::i;  // error: type mismatch
	pm = pf;  // error: type mismatch
}


// 20.6.3 Base and Derived Members
class Text : public Std_interface {
public:
	void start() override;
	void suspend() override;

	virtual void print();
};

void (Std_interface::* pmi)() = &Text::print;  // error
void (Text::* pmt)() = &Std_interface::start;  // OK