#include <map>
#include <string>
using namespace std;


namespace Parser {
	double prim(bool);
	double term(bool);
	double expr(bool);
}
namespace Lexer {
	enum class Kind : char;
	class Token;
	class Token_stream;
	Token_stream ts;
}
namespace Table {
	map<string, double> table;
}
namespace Driver {
	void calculate();
}
namespace Error {
	int no_of_errors;
	double error(const string& s);
}

double Parser::prim(bool get)
{
	using namespace Lexer;
	if (get) ts.get();
	switch (ts.current().kind) {
	case Kind::number:
	{
		double v = ts.current().number_value;
		ts.get();
		return v;
	}
	case Kind::name: {
		double& v = Table::table[ts.current().string_value];
		if (ts.get().kind == Kind::assign) v = expr(true);
		return v;
	}
	case Kind::minus:
		return -prim(true);
	case Kind::lp: {
		double e = expr(true);
		if (ts.current().kind != Kind::rp) return Error::error(" ')' expected");
		ts.get();
		return e;
	}
	default:
		return Error::error("primary expected");
	}
}