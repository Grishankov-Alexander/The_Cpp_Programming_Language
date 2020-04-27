#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Visitor;

class Node {
public:
	virtual void accept(Visitor&) = 0;
};

class Expr : public Node {
public:
	void accept(Visitor&) override;
};

class Stmt : public Node {
public:
	void accept(Visitor&) override;
};

class Visitor {
public:
	virtual void accept(Expr&) = 0;
	virtual void accept(Stmt&) = 0;
};

class Do1_visitor : public Visitor {
	void accept(Expr&) override { cout << "do1 to Expr" << '\n'; }
	void accept(Stmt&) override { cout << "do1 to Stmt" << '\n'; }
};

class Do2_visitor : public Visitor {
	void accept(Expr&) override { cout << "do2 to Expr" << '\n'; }
	void accept(Stmt&) override { cout << "do2 to Stmt" << '\n'; }
};

void Expr::accept(Visitor& v) { v.accept(*this); }
void Stmt::accept(Visitor& v) { v.accept(*this); }

void test(Expr& e, Stmt& s)
{
	Do1_visitor do1;
	Do2_visitor do2;
	vector<pair<Node*, Visitor*>> vn{
		{ &e, &do1 }, { &s, &do1 }, { &e, &do2 }, { &s, &do2 }
	};
	for (auto p : vn)
		p.first->accept(*p.second);
}

int main()
{
	Expr e1;
	Stmt s1;
	test(e1, s1);
}