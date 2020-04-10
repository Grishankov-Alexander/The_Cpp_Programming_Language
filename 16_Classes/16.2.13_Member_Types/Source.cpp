template<typename T>
class Tree {
	using value_type = T;  // member alias
	enum Policy { rb, splay, treeps };  // member enum
	class Node {
		Node* left;
		Node* right;
		value_type value;
	public:
		void f(Tree*);
	};
	Node* top;
public:
	void g(Node*);
};

template<typename T>
void Tree<T>::Node::f(Tree* p)
{
	top = right;  // error: no object of type Tree specified
	p->top = right;  // OK
	value_type v = left->value;  // OK: value_type is not associated with an object
}

template<typename T>
void Tree<T>::g(Tree<T>::Node* p)
{
	value_type val = right->value;  // error: no object of type Tree::Node
	value_type v = p->right->value;  // error: Node::right is private
	p->f(this);  // OK
}