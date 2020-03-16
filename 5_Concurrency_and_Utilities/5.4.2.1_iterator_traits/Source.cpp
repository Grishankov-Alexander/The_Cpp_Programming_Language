#include <vector>
#include <forward_list>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;


// for random-access iterators we can subscript into [beg:end)
template<typename Ran>
void sort_helper(Ran beg, Ran end, random_access_iterator_tag)
{
	sort(beg, end);
}

// for forward iterators we can traverse [beg:end)
template<typename For>
void sort_helper(For beg, For end, forward_iterator_tag)
{
	vector<decltype(*beg)> v{ beg, end };  // initialize a vector from [beg:end)
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), beg);  // copy the elements back
}

template<typename C>
using Iterator_type = typename C::iterator;  // C's iterator type

template<typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;  // Iter's category

template<typename C>
void sort(C& c)
{
	using Iter = Iterator_type<C>;
	sort_helper(c.begin(), c.end(), Iterator_category<Iter>{})
}

void test(vector<string>& v, forward_list<int>& lst)
{
	sort(v);  // sort the vector
	sort(lst);  // sort the singly-linked list
}