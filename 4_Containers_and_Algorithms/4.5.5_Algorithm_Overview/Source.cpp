// Overview of common std algorithms

// p=find(b,e,x)			p is the first p in [b:e) so that *p==x
// p=find_if(b,e,f)			p is the first p in [b:e) so that f(*p)==true
// n=count(b,e,x)			n is the number of elements *q in [b:e) so that *q==x
// n=count(b,e,f)			n is the number of elements *q in [b:e) so that f(*q)==true
// replace(b,e,v,v2)		replace elements *q in [b:e) so that *q==v by v2
// replace(b,e,f,v2)		replace elements *q in [b:e) so that f(*q) by v2
// p=copy(b,e,out)			copy [b:e) to [out:p)
// p=copy_if(b,e,out,f)		copy elements *q from [b:e) so that f(*q) to [out:p)
// p=unique_copy(b,e,out)	copy [b:e) to [out:p); don't copy adjacent duplicates
// sort(b,e)				sort elements of [b:e) using < as the sorting criterion
// sort(b,e,f)				sort elements of [b:e) using f as the sorting criterion
// (p1,p2)=equal_range(b,e,v)	[p1:p2) is the subsequence of the sorted sequence [b:e)
//								with the value v; basically a binary search for v
// p=merge(b,e,b2,e2,out)	merge two sorted sequences [b:e) and [b2:e2) into [out:p)