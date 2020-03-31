int f(int a
#ifdef arg_two
	, int b
#endif
);  // int f(int a);

#define arg_two "arg_two"
int g(int a
#ifdef arg_two
	, int b
#endif
);  // int g(int a, int b);

struct Call_info {
	Call_info* arg_one;
	Call_info* arg_two;  // Call_info* "arg_two";
};