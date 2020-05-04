#include <istream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;
#include <iostream>

template<typename Target = string, typename Source = string>
Target to(Source arg)  // convert Source to Target
{
	Target res;
	stringstream interpreter;
	if (
		!(interpreter << arg)  // if can't read from source
		|| !(interpreter >> res)  // or can't write to target
		|| !(ws(interpreter).eof())  // or stuff left in stream
		) throw runtime_error{ "to<>() failed" };
	return res;
}

int main(int argc, char** argv)
{
	auto x1 = to<string, double>(1.2);  // very explicit
	auto x2 = to<string>(1.2);  // source deduced to double
	auto x3 = to<>(1.2);  // Target defaults to string
	auto x4 = to(3.3);  // the <> is redundant
	cout << "x4 = " << x4 << endl;
}