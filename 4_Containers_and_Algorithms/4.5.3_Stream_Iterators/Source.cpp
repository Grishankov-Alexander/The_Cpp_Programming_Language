#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;


ostream_iterator<string> oo{ cout };  // write strings to cout

int hello_world()
{
	*oo = "Hello, ";  // meaning cout << "Hello, "
	++oo;
	*oo = "world\n";
}

istream_iterator<string> is{ cin };
istream_iterator<string> eos{};  // indicates end of input

// simple program to read a file, sort the words,
// eliminate duplicates and write to another file
int file_read_write()
{
	string from, to;
	cin >> from >> to;  // get source and target file names

	ifstream is{ from };  // input stream for file "from"
	istream_iterator<string> ii{ is };  // input iterator for stream
	istream_iterator<string> eos{};  // input sentinel

	ofstream os{ to };  // output stream for file "to"
	ostream_iterator<string> oo{ os, "\n" };  // output iterator for stream

	vector<string> b{ ii, eos };  // b is a vector initialized from input [ii:eos)
	sort(b.begin(), b.end());  // sort the buffer
	unique_copy(b.begin(), b.end(), oo);  // copy buffer output, discard replicated values

	return !is.eof() || !os;  // return error state
}

// another version
int read_write_file()
{
	string from, to;
	cin >> from >> to;
	ifstream is{ from };
	ofstream os{ to };
	set<string> b{ istream_iterator<string>{ is }, istream_iterator<string>{} };  // read input
	copy(b.begin(), b.end(), ostream_iterator<string>{ os, "\n" });  // copy to output
	return !is.eof() || !os;
}