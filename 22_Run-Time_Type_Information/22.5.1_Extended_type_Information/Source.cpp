#include <typeindex>
#include <typeinfo>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


map<string, Layout> layout_table;
void f(B* p)
{
	Layout& x = layout_table[typid(*p).name()];  // find the layout base on *p's name
}

unordered_map<type_index, Icon> icon_table;
void g(B* p)
{
	Icon& i = icon_table[type_index{ typeid(*p) }];
}