template<class Iter, class Value>
Iter find(Iter first, Iter last, Value val)
{
	while (first != last && *first != val) ++first;
	return first;
}