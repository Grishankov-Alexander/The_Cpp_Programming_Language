#include <vector>
#include <iostream>

template<typename N, typename Balance>
struct Node_base : Balance {
	N* left;
	N* right;
	
	Node_base();
	void insert(N& n)
	{
		if (this->compare(n, *left)) {  // Balance::compare
			// ... do something
		}
		else {}
	}
};

template<typename Val, typename Balance>
struct Search_node : public Node_base<Search_node<Val, Balance>, Balance>
{
	Val val;  // user data
	Search_node(Val v = Val{}) : val{ v } {}
};

struct Red_black_balance {
	template<typename T> bool compare(T& left, T& right);
};  // red-black tree

template<typename T>
using Rbnode = Search_node<T, Red_black_balance>;
using My_node = Rbnode<double>;

My_node my_root;  // a red-black tree of doubles
void user(const std::vector<double>& v)
{
	for (auto x : v)
		my_root.insert(*new My_node{ x });
}