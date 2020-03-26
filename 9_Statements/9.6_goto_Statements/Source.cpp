void do_something(int i, int j)
// do something to a two-dimensional matrix called mn
{
	for (i = 0; i != n; ++i)
		for (j = 0; j != m; ++j)
			if (nm[i][j] == a)
				goto found;
	// not found
found:
	// nm[i][j] == a
}