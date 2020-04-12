
class A {
private:
	int a{ 7 };  // default for a
	int b{ 5 };
	HashFunction algorithm{ "MD5" };  // hash to be applied to all As
	string state{ "Constructor run" };  // indicate state in object lifecycle
public:
	A() {}  // same as A() : a{7},b{5},algorithm{"MD5"},state{"constructor run"} {}
	A(int a_val) : a{ a_val } {}  // same as up but A(int a_val) : a{a_val}, ...
	A(D d) : b{ g(d) } {}  // A(D d) : a{7},b{g(d)}, ...
};