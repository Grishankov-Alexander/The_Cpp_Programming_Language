int x = f2() + g3();  // undefined whether f() or g() is called first
int i = 1;
v[i] = i++;  // undefined result
f1(v[i], i++);  // two arguments
f2((v[i], i++));  // one argument