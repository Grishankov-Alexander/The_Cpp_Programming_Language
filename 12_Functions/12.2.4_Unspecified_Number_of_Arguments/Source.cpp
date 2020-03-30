#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>
#include <cstdio>
#include <cstdarg>
using namespace std;


void f()
{
	printf("Hello, world!\n");
	printf("My name is %s %s\n", "g*y", "lord");
	printf("%d + %d = %d\n", 2, 3, 5);
}

void error(int severity ...)  // "severity" followed by a zero-terminated list of char*s
{
	va_list ap;
	va_start(ap, severity);  // arg startup
	for (;;) {
		char* p = va_arg(ap, char*);
		if (p == nullptr) break;
		cerr << p << ' ';
	}
	va_end(ap);  // arg cleanup
	cerr << '\n';
	if (severity) exit(severity);
}
char* itoa(int i, char a[]) { sprintf_s(a, sizeof(int), "%d", i); return a; }  // int to alpha
int main(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		error(0, argv[0], nullptr);
		break;
	case 2:
		error(0, argv[0], argv[1], nullptr);
		break;
	default:
		char buffer[8];
		error(1, argv[0], "with", itoa(argc - 1, buffer), "arguments", nullptr);
	}
}

void error(int severity, initializer_list<string> err)
{
	for (auto& s : err)
		cerr << s << ' ';
	cerr << '\n';
	if (severity) exit(severity);
}
int main2(int argc, char* argv[])
{
	switch (argc) {
	case 1:
		error(0, { argv[0] });
		break;
	case 2:
		error(0, { argv[0], argv[1] });
		break;
	default:
		error(1, { argv[0], "with", to_string(argc - 1), "arguments" });
	}
	return 0;
}

void error(int severity, const vector<string>& err)  // almost as before
{
	for (auto& s : err) cerr << s << ' ';
	cerr << '\n';
	if (severity) exit(severity);
}
vector<string> arguments(int argc, char* argv[])
{
	vector<string> res;
	for (int i = 0; i != argc; ++i) res.push_back(argv[i]);
	return res;
}
int main3(int argc, char* argv[])
{
	auto args = arguments(argc, argv);
	error((args.size() < 2) ? 0 : 1, args);
	return 0;
}