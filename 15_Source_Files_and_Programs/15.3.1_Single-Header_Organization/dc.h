#include <map>
#include <string>
#include <iostream>

namespace Parser {
	double expr(bool);
	double term(bool);
	double prim(bool);
}

namespace Lexer {
	enum class Kind : char {
		name, number, end,
		plus='+', minus='-', mul='*', div='/', print=';',
		assign='=', lp='(', rp=')'
	};

	struct Token {
		Kind kind;
		std::string string_value;
		double number_value;
	};

	class Token_stream {
	private:
		std::istream* ip;
		bool owns;
		Token ct{ Kind::end };
		void close() { if (owns) delete ip; }
	public:
		Token_stream(std::istream& s) : ip{ &s }, owns{ false }, ct{ Kind::end } {}
		Token_stream(std::istream* p) : ip{ p }, owns{ true }, ct{ Kind::end } {}
		~Token_stream() { close(); }

		Token get();  // read and return next token
		Token& current();  // most recently read token

		void set_input(std::istream& s) { close(); ip = &s; owns = false; }
		void set_input(std::istream* p) { close(); ip = p; owns = true; }
	};

	extern Token_stream ts;
}

namespace Error {
	extern int no_of_errors;
	double error(const std::string& s);
}

namespace Table {
	extern std::map<std::string, double> table;
}

namespace Driver {
	void calculate();
}