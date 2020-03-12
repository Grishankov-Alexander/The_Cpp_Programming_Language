#include <string>
using namespace std;


string compose(const string& name, const string& domain)
{
	return name + '@' + domain;
}

auto addr = compose("dmr", "bell-labs.com");

void m2(string& s1, string& s2)
{
	s1 = s1 + '\n';  // append newline
	s2 += '\n';  // append newline
}

string name = "Niels Stroustrup";

void m3()
{
	string s = name.substr(6, 10);  // s = "Stroustrup"
	name.replace(0, 5, "nicholas");  // name becomes "nicholas Stroustrup"
	name[0] = toupper(name[0]);  // name becomes "Nicholas Stroustrup"
}

string incantation;

void respond(const string& answer)
{
	if (answer == incantation) {
		// perform magic
	}
	else if (answer == "yes") {
		// ...
	}
	// ...
}