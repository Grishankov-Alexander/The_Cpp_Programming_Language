struct Enode {
	Token_value oper;
	Enode* left;
	Enode* right;
};

Enode* expr(bool get)
{
	Enode* left = term(get);
	switch (ts.current().kind) {
	case Kind::plus:
	case Kind::minus:
		left = new Enode{ ts.current().kind, left, term(true) };
		break;
	default:
		return left;  // return node
	}
}

void generate(Enode* n)
{
	switch (n->oper) {
	case Kind::plus:
		// use n
		delete n;  // delete an Enode from the free store
	}
}

int* p = new int = 7;  // error
auto pc = new complex<double>;  // the complex is initialized to {0,0}
auto pi = new int;  // the int is uninitialized
auto pc = new complex<double>{};  // the complex is initialized to {0,0}
auto pi = new int{};  // the int is initialized to 0
