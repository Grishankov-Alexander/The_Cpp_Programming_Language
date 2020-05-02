template<typename C> class string;

template<typename C>
bool operator<(const string<C>& s1, const string<C>& s2)
{
	if (s2.size() < s1.size()) return false;
	bool eq = true;
	for (int i = 0; (i != s1.size()) && (i != s2.size()); ++i) {
		if (s2[i] < s1[i]) return false;
		if (s2[i] > s1[i]) eq = false;
	}
	if (s1.size() == s2.size() && eq) return false;
	return true;
}