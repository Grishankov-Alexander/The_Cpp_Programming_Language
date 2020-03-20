using rr_i = int&&;
using lr_i = int&;
using rr_rr_i = rr_i&&;  // is an int&&
using lr_rr_i = rr_i&;  // int&
using rr_lr_i = lr_i&&;  // int&
using lr_lr_i = lr_i&;  //int&

rr_rr_i r1 = 10;
rr_lr_i r2 = r1;