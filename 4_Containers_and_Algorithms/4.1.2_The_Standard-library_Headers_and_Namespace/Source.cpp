#include <string>  // make the standard string facilities accessible
#include <list>


std::string s{ "Four legs Good; two legs Baaad!" };
std::list<std::string> slogans{ "War is peace",
	"Freedom is Slavery", "Ignorance is Strength" };

using namespace std;  // make std names available without std:: prefix

// OK: string is std::string
string s{ "C++ is a general-purpose programming language" };

// Here is a selection of standard-library headers
// header		 	declarations
// --------------|--------------
// <algorithm>		copy(), find(), sort()
// <array>			array
// <chrono>			duration, time_point
// <cmath>			sqrt(), pow()
// <complex>		complex, sqrt(), pow()
// <fstream>		fstream, ifstream, ofstream
// <future>			future, promise
// <iostream>		istream, ostream, cin, cout
// <map>			map, multimap
// <memory>			unique_ptr, shared_ptr, allocator
// <random>			default_random_engine, normal_distribution
// <regex>			regex, smatch
// <string>			string, basic_string
// <set>			set, multiset
// <sstream>		istrstream, ostrstream
// <thread>			thread
// <unordered_map>	unordered_map, unordered_multimap
// <utility>		move(), swap(), pair
// <vector>			vector
