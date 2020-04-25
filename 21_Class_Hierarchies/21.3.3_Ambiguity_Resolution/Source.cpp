

struct Debug_info {};

class Satellite {
public:
	virtual Debug_info get_debug();
};

class Displayed {
public:
	virtual Debug_info get_debug();
};

class Comm_sat
	: public Satellite, public Displayed {};

void f(Comm_sat& cs)
{
	Debug_info di = cs.get_debug();  // error: ambiguous
	di = cs.Satellite::get_debug();  // OK
	di = cs.Displayed::get_debug();  // OK
}

// or
Debug_info connect_debugs(const Debug_info& a, const Debug_info& b);

class Comm_sat
	: public Satellite, public Displayed
{
public:
	Debug_info get_debug() override
	{
		return connect_debugs(
			Satellite::get_debug(), Displayed::get_debug()
		);
	}
};


class Window {
public:
	virtual void draw();  // display image
};

class Cowboy {
public:
	virtual void draw();  // pull gun from holster
};

struct WWindow : Window
{
	using Window::Window;  // inherit constructors
	virtual void win_draw() = 0;  // force derived class to override
	void draw() override final { win_draw(); }  // can't be declared in derived classes
};

struct CCowboy : Cowboy
{
	using Cowboy::Cowboy;
	virtual void cow_draw() = 0;
	void draw() override final { cow_draw(); }
};

class Cowboy_window
	: public CCowboy, public WWindow
{
	void win_draw() override;
	void cow_draw() override;
};