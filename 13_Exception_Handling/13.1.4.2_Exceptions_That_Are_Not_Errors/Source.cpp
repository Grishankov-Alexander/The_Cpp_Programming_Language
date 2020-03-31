#include <string>
using namespace std;


struct Tree {
	Tree* left;
	Tree* right;
	string str;
};

void fnd(Tree* p, const string& s)
{
	if (s == p->str) throw p;  // found s
	if (p->left) fnd(p->left, s);
	if (p->right) fnd(p->right, s);
}
Tree* find(Tree* p, const string& s)
{
	try {
		fnd(p, s);
	}
	catch (Tree * q) {  // q->str == s
		return q;
	}
	return 0;
}