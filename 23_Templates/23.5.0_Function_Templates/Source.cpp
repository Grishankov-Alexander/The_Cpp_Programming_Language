#include <functional>
#include <utility>
#include <vector>
#include <string>
using namespace std;


template<typename T, typename Compare = less<T>>
void sort(vector<T>& v)
	// Shell sort (Knuth, Vol. 3, pg. 84)
{
	Compare cmp;  // make a default Compare object
	const size_t n{ v.size() };

	for (int gap = n / 2; gap > 0; gap /= 2)
		for (int i = gap; i != n; ++i)
			for (int j = i - gap; j >= 0; j -= gap)
				if (cmp(v[i], v[j]))
					swap(v[i], v[j]);
}

struct No_case {
	bool operator()(const string& a, const string& b) const;  // compare case insensitive
};

void f(vector<int>& vi, vector<string>& vs)
{
	sort(vi);
	sort<int, greater<int>>(vi);  // sort using greater

	sort(vs);
	sort<string, No_case>(vs);  // sort using No_case
}