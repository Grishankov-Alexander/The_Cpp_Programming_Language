#include <vector>
#include <iostream>
using namespace std;


void f1()
{
	int var = 1;
	int& r{ var };  // r and var now refer to the same int
	int x = r;  // x becomes 1
	r = 2;  // var becomes 2
}

int var = 1;
int& r1{ var };  // OK: r1 initialized
int& r2;  // error: initializer missing
extern int& r3;  // OK: r3 initialized elsewhere

void g1()
{
	int var = 0;
	int& rr{ var };
	++rr;  // var is incremented to 1
	int* pp = &rr;  // pp points to var
}

double& dr = 1;  // error: lvalue needed
const double& cdr{ 1 };  // OK. make following steps:
double temp = double{ 1 };  // first create a temporary with the right value
const double& cdr{ temp };  // then use the temp as the initializer for cdr

void increment(int& aa)
{
	++aa;
}
void f2()
{
	int x = 1;
	increment(x);  // x = 2
}

int next(int p) { return p + 1; }
void g2()
{
	int x = 1;
	increment(x);  // x = 2
	x = next(x);  // x = 3
}


template<class K, class V>
class Map {  // a simple map class
	vector<pair<K, V>> elem;  // {key,value} pairs
public:
	V& operator[](const K& k);  // return ref to value corresponding to the key k
	pair<K, V>* begin() { return &elem[0]; }
	pair<K, V>* end() { return &elem[0] + elem.size(); }
};

template<class K, class V>
V& Map<K, V>::operator[](const K& k)
{
	for (auto& x : elem)
		if (k == x.first)
			return x.second;
	elem.push_back({ k, V{} });  // add pair at end
	return elem.back().second;  // return the (default) value of the new element
}

int main()  // count the number of occurences of each word on input
{
	Map<string, int> buf;
	for (string s; cin >> s;) ++buf[s];
	for (const auto& x : buf)
		cout << x.first << ": " << x.second << '\n';
}