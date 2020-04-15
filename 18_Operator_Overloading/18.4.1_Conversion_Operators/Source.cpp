class Tiny {
	char v;
	void assign(int i) { if (i & ~63) throw Bad_range{}; v = i;
}
public:
	struct Bad_range { const char* message{ "Tiny::Bad range" }; };
	Tiny(int i) { assign(i); }
	operator int() const { return v; }  // conversion to int function
};

int main(int argc, char* argv[])
{
	Tiny c1 = 2;
	Tiny c2 = 62;
	Tiny c3 = c2 - c1;  // c3 = 60
	Tiny c4 = c3;
	int i = c1 + c2;  // i=64
	c1 = c1 + c2;  // range error
	i = c3 - 64;  // ok
	c2 = c3 - 64;  // range error
}

int operator+(Tiny, Tiny);
void f(Tiny t, int i)
{
	t + i;  // error: ambiguous( int(t) + i or operator+(t, Tiny(i)))
}