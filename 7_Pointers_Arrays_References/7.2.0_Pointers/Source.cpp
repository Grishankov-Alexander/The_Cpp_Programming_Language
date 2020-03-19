char c = 'a';
char* pc = &c;  // p holds the &(address of) c
char c2 = *pc;  // c2=='a'; * is the dereference operator

int* pi;  // pointer to int
char** ppc;  // pointer to pointer to char
int* ap[15];  // array of 15 pointers to ints
int (*fp)(char*);  // pointer to function taking a char* argument; returns an int
int* f(char*);  // function taking a char* argument; returns a pointer to int