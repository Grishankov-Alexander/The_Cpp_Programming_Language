struct Link {
	Link* previous;
	Link* successor;
};

struct No_good {
	No_good member;  // error: recursive definition
};

struct List;  // struct name declaration: List to be defined later
struct Link2 {
	Link2* pre;
	Link2* suc;
	List* member_of;
	int data;
};
struct List {
	Link* head;
};

struct S;  // "S" is the name of some type
extern S a;
S f();
void g(S);
S* h(S*);
void k(S* p)
{
	S a;  // error: S not defined; size needed to allocate
	f();  // error: S not defined; size needed to return value
	g(a);  // error: S not defined; size needed to pass argument
	p->m = 7;  // error: S not defined; member name not known
	S* q = h(p);  // ok: pointers can be allocated and passed
	q->m = 7;  // error: S not defined; member name not known
}

struct stat { /*...*/ };
int stat(char* name, struct stat* buf);