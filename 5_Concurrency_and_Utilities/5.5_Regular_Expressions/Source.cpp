#include <regex>
#include <iostream>
#include <string>
using namespace std;


regex pat(R"(\w{2}\s*\d{5}(-\d{4})?)");  // ZIP code pattern: XXddddd-dddd
int main()
{
	int lineno = 0;
	for (string line; getline(cin, line);) {  // read into line buffer
		++lineno;
		smatch matches;  // matched strings go here
		if (regex_search(line, matches, pat))
			cout << lineno << ": " << matches[0] << "\n";
	}
}