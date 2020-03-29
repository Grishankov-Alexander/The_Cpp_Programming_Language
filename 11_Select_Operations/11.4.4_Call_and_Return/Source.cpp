void f(double y);

void g(double y)
{
	[&] { f(y); };  // return type is void
	auto z1 = [=](int x) { return x + y; };  // return double
	auto z2 = [=] { if (y) return 1; else return 2; };  // error: body too complicated
													// for return type deduction
	auto z3 = [y]() { return y ? 1 : 2; };  // int return deduced
	auto z4 = [y]() -> int { if (y) return 1; else return 2; };  // explicit return type
}