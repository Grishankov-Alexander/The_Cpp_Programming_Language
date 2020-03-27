#include <string>
#include <map>
#include <istream>
#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;


double expr(bool get);
double prim(bool get);
double term(bool get);
int no_of_errors;
map<string, double> table;


double error(const string& s)
{
	no_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}


enum class Kind : char {
	name, number, end,
	plus = '+', minus = '-', mul = '*', div = '/',
	print = ';', assign = '=', lp = '(', rp = ')'
};


struct Token {
	Kind kind;
	string string_value;
	double number_value;
};


class Token_stream {
private:
	istream* ip;  // pointer to an input stream
	bool owns;  // does the Token_stream own the istream ?
	Token ct{ Kind::end };  // current token
	void close() { if (owns) delete ip; }
public:
	Token_stream(istream* p) : ip{ p }, owns{ true } {}
	Token_stream(istream& s) : ip{ &s }, owns{ false } {}
	~Token_stream() { close(); }

	Token get();  // read and return next token
	Token& current() { return ct; }  // most recently read token
	void set_input(istream* p) { close(); ip = p; owns = true; }
	void set_input(istream& s) { close(); ip = &s; owns = false; }
};

Token Token_stream::get()
{
	char ch;
	do {  // skip whitespace except '\n'
		if (!ip->get(ch)) return ct = { Kind::end };
	} while (ch != '\n' && isspace(ch));

	switch (ch) {
	case ';':
	case '\n':
		return ct = { Kind::print };
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return ct = { static_cast<Kind>(ch) };
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': case '.':
		ip->putback(ch);  // put the first digit (or .) back into the istream
		*ip >> ct.number_value;  // read number into ct
		ct.kind = Kind::number;
		return ct;
	default:  // name, name =, or error
		if (isalpha(ch)) {
			ct.string_value = ch;
			while (ip->get(ch) && isalnum(ch))
				ct.string_value += ch;  // append
			ip->putback(ch);
			ct.kind = Kind::name;
			return ct;
		}
		error("bad token");
		return ct = { Kind::print };
	}
}


Token_stream ts{ cin };


double expr(bool get)  // add and subtract
{
	double left = term(get);
	for (;;) {  // forever
		switch (ts.current().kind) {
		case Kind::plus:
			left += term(true);
			break;
		case Kind::minus:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}


double term(bool get)  // multiply and divide
{
	double left = prim(get);
	for (;;) {
		switch (ts.current().kind) {
		case Kind::mul:
			left *= prim(true);
			break;
		case Kind::div:
			if (auto d = prim(true)) {
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left; 

		}
	}
}


double prim(bool get)
// handle primaries
{
	if (get) ts.get();  // read next token
	switch (ts.current().kind) {
	case Kind::number:  // floating-point constant
	{
		double v = ts.current().number_value;
		ts.get();
		return v;
	}
	case Kind::name:
	{
		double& v = table[ts.current().string_value];  // find the corresponding
		if (ts.get().kind == Kind::assign) v = expr(true);  // '=' seen: assignment
		return v;
	}
	case Kind::minus:  // unary minus
		return -prim(true);
	case Kind::lp:
	{
		auto e = expr(true);
		if (ts.current().kind != Kind::rp) return error("')' expected");
		ts.get();  // eat
		return e; 
	}
	default:
		return error("primary expected");
	}
}


void calculate()
{
	for (;;) {
		ts.get();
		if (ts.current().kind == Kind::end) break;
		if (ts.current().kind == Kind::print) continue;
		cout << expr(false) << '\n';
	}
}


int main(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		break;  // read from stdin
	case 2:  // read from argument string
		ts.set_input(new istringstream{ argv[1] });
		break;
	default:
		error("too many arguments");
		return 1;
	}

	table["pi"] = 3.141592653589;
	table["e"] = 2.718281828459;
	calculate();
	return no_of_errors;
}