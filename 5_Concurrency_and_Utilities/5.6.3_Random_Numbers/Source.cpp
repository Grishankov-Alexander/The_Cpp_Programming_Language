#include <random>
#include <functional>
#include <iostream>
using namespace std;


using my_engine = default_random_engine;  // type of engine
using my_distribution = uniform_int_distribution<>;  // type of distribution

my_engine re{};  // the default engine
my_distribution one_to_six{ 1, 6 };  // distribution that maps to the ints 1..6
auto die = bind(one_to_six, re);  // make a generator

int x = die();  // roll the die: x becomes a value in [1:6]

void f()
{
	auto die = bind(uniform_int_distribution<>{ 1, 6 }, default_random_engine{});
}

class Rand_int {
	default_random_engine re;
	uniform_int_distribution<> dist;
public:
	Rand_int(int low, int high) : dist{ low, high } {}
	int operator()() { return dist(re); }  // draw an int
};

Rand_int rnd{ 1, 10 };  // make a random number generagor for [1:10]
int y = rnd();  // x is a number in [1:10]

int main()
{
	Rand_int rnd{ 0, 4 };  // make a uniform random number generator
	vector<int> histogram(5);  // make a vector of size 5
	for (int i = 0; i != 200; ++i)
		++histogram[rnd()];  // fill histogram with the frequencies of numbers [0:4]
	for (int i = 0; i != histogram.size(); ++i) {  // write out a bar graph
		cout << i << '\t';
		for (int j = 0; j != histogram[i]; ++j)
			cout << '*';
		cout << endl;
	}
}