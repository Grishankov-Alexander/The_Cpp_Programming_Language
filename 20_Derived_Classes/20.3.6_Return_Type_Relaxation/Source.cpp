

class Expr {
public:
	Expr();  // default constructor
	Expr(const Expr&);
	virtual Expr* new_expr() = 0;
	virtual Expr* clone() = 0;
};
class Cond : public Expr {
public:
	Cond();
	Cond(const Cond&);
	Cond* new_expr() override { return new Cond(); }
	Cond* clone() override { return new Cond(*this); }
};

void user(Expr* pe, Cond* pc)
{
	Expr* p1 = pe->new_expr();
	Cond* p2 = pc->clone();
	Cond* p3 = pe->new_expr();  // no conversion from Expr* to Cond*
}