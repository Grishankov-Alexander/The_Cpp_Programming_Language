#include <future>
#include <vector>
using namespace std;


double comp4(vector<double>& v)
// spawn many tasks if v is large enough
{
	if (v.size() < 10000) return accum(v.begin(), v.end(), 0.0);

	auto v0 = &v[0];
	auto sz = v.size();
	auto f0 = async(accum, v0, v0 + sz / 4, 0.0);  // first quarter
	auto f1 = async(accum, v0 + sz / 4, v0 + sz / 2, 0.0);  // second quarter
	auto f2 = async(accum, v0 + sz / 2, v0 + sz * 3 / 4, 0.0);  // third quarter
	auto f3 = async(accum, v0 + sz * 3 / 4, v0 + sz, 0.0);  // fourth quarter

	return f0.get() + f1.get() + f2.get() + f3.get();  // collect and combine the results
}