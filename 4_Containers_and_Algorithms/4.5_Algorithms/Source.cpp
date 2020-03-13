#include <vector>
#include <list>
#include <algorithm>
using namespace std;


// define comparison operator for the type Entry so it can be sorted
bool operator<(const Entry& x, const Entry& y)  // less than
{
	return x.name < y.name;  // order Entrys be their names
}

// sort a vector and place a copy of each unique element on a list
// list should have the size equal or more than number of unique elements
void f(vector<Entry>& vec, list<Entry> lst)
{
	sort(vec.begin(), vec.end());  // use < for order
	// don't copy adjacent equal elements
	unique_copy(vec.begin(), vec.end(), lst.begin());
}

// to place the unique elements in a new container
list<Entry> f(vector<Entry>& vec)
{
	list<Entry> res;
	sort(vec.begin(), vec.end());
	unique_copy(vec.begin(), vec.end(), back_inserter(vec));  // append to res
	return res;
}