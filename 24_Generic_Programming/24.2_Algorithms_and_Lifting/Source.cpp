#include <functional>


/*
double add_all(double* array, int n)
// one concrete algorithm on array of doubles
{
	double s{ 0 };
	for (int i = 0; i != n; ++i)
		s += array[i];
	return s;
}

struct Node {  // single-linked list
	Node* next;
	int data;
};

int sum_elements(Node* first, Node* last)
// another concrete algorithm on list of ints
{
	int s{};
	while (first != last) {
		s += first->data;
		first = first->next;
	}
	return s;
}

// concrete STL-like code:
template<typename Iter, typename Val>
Val sum(Iter first, Iter last)
{
	Val s{};
	while (first != last) {
		s += *first;
		++first;
	}
	return s;
}

double ad[]{ 1, 2, 3, 4 };
double s = sum<double*, double>(ad, ad + 4);

Node* operator++(Node* p) { return p->next; }
int operator*(Node* p) { return p->data; }
Node* end(Node*) { return nullptr; }

void test(Node* lst)
{
	int s = sum<Node*, int>(lst, end(lst));
}

template<typename Iter, typename Val = int>
Val accumulate(Iter first, Iter last, Val initial_val = Val{})
{
	while (first != last) {
		initial_val += *first;
		++first;
	}
	return initial_val;
}
double ad[]{ 1, 2, 3, 4 };
double s1 = accumulate(ad, ad + 4, 0.0);  // accumulate in a double
auto s2 = accumulate(ad, ad + 4);  // accumulate in an int
*/

template<typename Iter, typename Val, typename Oper>
Val accumulate(Iter first, Iter last, Val s, Oper op)
{
	while (first != last) {
		s = op(s, *first);
		++first;
	}
	return s;
}

double ad[]{ 1, 2, 3, 4 };
double s1 = accumulate(ad, ad + 4, 0.0, std::plus<double>{});