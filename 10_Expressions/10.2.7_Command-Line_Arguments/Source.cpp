#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


Token_stream ts{ cin };
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

vector<string> arguments(int argc, char* argv[])
{
	vector<string> res;
	for (int i = 0; i != argc; ++i)
		res.push_back(argv[i]);
	return res;
}