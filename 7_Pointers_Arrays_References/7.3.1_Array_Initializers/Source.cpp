int v1[] = { 1, 2, 3, 4 };
char v2[] = { 'a', 'b', 'c', 0 };
char v3[2] = { 'a', 'b', 0 };  // error: too many initializers
char v4[3] = { 'a', 'b', 0 };  // OK
int v5[8] = { 1, 2, 3, 4 };  // == v6
int v6[] = { 1, 2, 3, 4, 0, 0, 0, 0 };
int v7[8] = v5;  // error: can't copy an array (cannot assign an int* to an array)
v7 = v5;  // error: no array assignment