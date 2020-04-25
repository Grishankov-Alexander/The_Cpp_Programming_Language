#include <memory>

class BBwidget {};  // ui implementation
class CWwidget {};  // other ui implementation

class Ival_box {};
class Ival_dial : public Ival_box {};
class Ival_slider : public Ival_box {};
class Popup_ival_slider : public Ival_slider {};

class BB_ival_dial
	: public Ival_dial, protected BBwidget {
public:
	BB_ival_dial(int, int);
};
class CW_ival_dial
	: public Ival_dial, protected CWwidget {
public:
	CW_ival_dial(int, int);
};

class Ival_maker {
public:
	virtual Ival_dial* dial(int, int) = 0;  // make dial
	virtual Popup_ival_slider* popup_slider(int, int) = 0;
};

class BB_maker : public Ival_maker {  // make BB versions
public:
	Ival_dial* dial(int, int) override;
	Popup_ival_slider* popup_slider(int, int) override;
};

class CW_maker : public Ival_maker {
public:
	Ival_dial* dial(int, int) override;
	Popup_ival_slider* popup_slider(int, int) override;
};

Ival_dial* BB_maker::dial(int a, int b)
{
	return new BB_ival_dial{ a, b };
}
Ival_dial* CW_maker::dial(int a, int b)
{
	return new CW_ival_dial{ a, b };
}

void user(Ival_maker& im)
{
	std::unique_ptr<Ival_box> pb{ im.dial(0, 99) };  // create appropriate dial
}

BB_maker BB_impl;  // for BB users
CW_maker CW_impl;

void driver()
{
	user(BB_impl);  // use BB
	user(CW_impl);
}