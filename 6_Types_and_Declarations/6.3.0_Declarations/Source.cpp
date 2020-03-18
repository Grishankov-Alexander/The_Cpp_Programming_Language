#include <string>
#include <complex>
#include <vector>
using namespace std;


// pure declarations
double sqrt(double);  // function declaration
extern int error_number;  // variable declaration
struct User;  // type name declaration

// their definitions
double sqrt(double d) {/*...*/ }
int error_number = 1;
struct User { /*...*/ };

// there can be many declarations but exactly one definition
int count;
int count;  // error: redefenition
extern int error_number;  // OK, redeclaration
extern short error_number;  // error: type mismatch

// some definitions
struct Date { int d, m, y; };  // Date is a struct with three members
using Point = std::complex<short>;  // Point is a name for std::complex<short>
int day(Date* p) { return p->d; }
const double pi{ 3.141592653 };

void f()
{
	int count{ 1 };  // initialize count to 1
	const char* name{ "Bjarne" };  // name is a variable that points to a constant
	count = 2;
	name = "Martinnn";
}

// definitions that do not specify values
char ch;  // set aside memory for a char and initialize it to 0
auto count = 1;  // set aside memory for an int initialized to 1
const char* name = "Njal";  // set aside memory for a pointer to char
							// set aside memory for a string literal "Njal"
							// initialize the pointer with the address of that string literal
string s;

const char* season[]{ "spring", "summer", "fall", "winter" };
vector<string> people{ name, "Skarphedin", "Gunnar" };
template<class T> T abs(T a) { return a < 0 ? -a : a; };
constexpr int fac(int n) { return n < 2 ? 1 : (n * fac(n - 1)); }  // possible compile-time evaluation
constexpr double zz{ ii * fac(7) };  // compile-time initialization
enum class Beer { Carlsberg, Tuborg, Thor, IPA };
namespace NS { int a; }