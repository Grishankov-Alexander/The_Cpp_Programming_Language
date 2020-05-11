

class Nil {};

template<int I, class T1 = Nil, class T2 = Nil, class T3 = Nil, class T4 = Nil>
struct select;
template<class T1, class T2, class T3, class T4>
struct select<0, T1, T2, T3, T4> { using type = T1; };  // specialize for N==0
template<class T1, class T2, class T3, class T4>
struct select<1, T1, T2, T3, T4> { using type = T2; };
template<class T1, class T2, class T3, class T4>
struct select<2, T1, T2, T3, T4> { using type = T3; };
template<class T1, class T2, class T3, class T4>
struct select<3, T1, T2, T3, T4> { using type = T4; };

template<int I, class T1 = Nil, class T2 = Nil, class T3 = Nil, class T4 = Nil>
using Select = typename select<I, T1, T2, T3, T4>::type;

typename select<3>::type i;  // will select the default
Select<3> i2;  // same
Select<2, int, long, long long> l1;  // long long

 
// implement select with variadic templates
namespace variadic_select {

    template<unsigned N, class... Cases>  // general case; never instantiate
    struct select;

    template<unsigned N, class T, class... Cases>
    struct select<N, T, Cases...> : select<N - 1, Cases...> {};

    template<class T, class... Cases>  // final case: N == 0
    struct select<0, T, Cases...> { using type = T; };

    template<unsigned N, class... Cases>
    using Select = typename select<N, Cases...>::type;

    Select<2, char, short, int> var;  // int
    Select<2, char, short> err;
}