

class BB_ival_slider
	: public Ival_slider, protected BBslider {};

void f(BB_ival_slider* p)
{
	Ival_slider* pi1 = p;  // OK
	Ival_slider* pi2 = dynamic_cast<Ival_slider*>(p);  //OK

	BBslider* pbb1 = p;  // error: BBslider is protected base
	BBslider* pbb2 = dynamic_cast<BBslider*>(p);  // OK: pbb2 is nullptr
}

class My_slider : public Ival_slider {  // polymorphic base (Ival_slider has virtual functions)
	// ...
};

class My_date : public Date {  // base not polymorphic (Date has no virtual functions)
	// ...
};

void g(Ival_box* pb, Date* pd)
{
	My_slider* ps = dynamic_cast<My_slider*>(pb);  // OK
	My_date* pmd = dynamic_cast<My_date*>(pd);  // error: Date not polymorphic
}


// 22.2.1.1 dynamic_cast to Reference
void fp(Ival_box* p)
{
	if (Ival_slider* is = dynamic_cast<Ival_slider*>(p)) {  // does p point to an Ival_slider ?
		// ... use is
	}
	else { /* *p is no an Ival_slider; handle alternatives */ }
}

voif fr(Ival_box& r)
{
	try {
		Ival_slider& is = dynamic_cast<Ival_slider&>(r);  // r references an Ival_slider!
	}
	catch (bad_cast) { /* handle */ }
}


void g(BB_ival_slider& slider, BB_ival_dial& dial)
// BB_ival_dial doesn't inherit from Ival_slider
{
	fp(&slider);  // BB_ival_slider* passed as Ival_box*
	fr(slider);  // BB_ival_slider& passed as Ival_box&
	fp(&dial);  // will be nullptr
	fr(dial);  // bad_cast
}