#include <memory>
using namespace std;

class BBwidget {};  // parent of all gui widgets

class Ival_box : public BBwidget {
protected:
	int val;
	int low, high;
	bool changed{ false };  // changed by user using set_default()
public:
	Ival_box(int l, int h) : val{ l }, low{ l }, high{ h } {}

	virtual int get_value() { changed = false; return val; }  // for application
	virtual void set_value(int i) { changed = true; val = i; }  // for user
	virtual void reset_value(int i) { changed = false; val = i; }
	virtual void prompt() {}
	virtual bool was_changed() const { return changed; }
	
	virtual ~Ival_box() {}
};

void interact(Ival_box* pb)
{
	pb->prompt();  // alert user
	int i = pb->get_value();
	if (pb->was_changed()) {
		// new value, do something
	}
	else { /* do something else */ }
}

class Ival_slider : public Ival_box { 
private:
	// ... graphics stuff to define what the slider looks like
public:
	Ival_slider(int, int);
	int get_value() override;  // get value from user and deposit it in val
	void prompt() override;
};

void some_fct()
{
	unique_ptr<Ival_box> p1{ new Ival_slider{ 0, 5 } };
	interact(p1.get());
}

