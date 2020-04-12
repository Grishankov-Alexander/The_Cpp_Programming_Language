

class B1 { public: B1(); };  // has default constructor
class B2 { public: B2(int); };  // no default constructor
struct D1 : B1, B2 {
public:
	D1(int i) : B1{}, B2{ i } {}
};
struct D2 : B1, B2 {
public:
	D2(int i) : B2{ i } {}  // B1{} is used implicitly
};
struct D3 : B1, B2 {
public:
	D3(int i) {}  // error: B2 requires an int initializer
};