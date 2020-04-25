

class BBwidget {};  // implementation for ui widgets

class Ival_box {
public:
	virtual int get_value() = 0;
	virtual void set_value(int) = 0;
	virtual void reset_value(int) = 0;
	virtual void prompt() = 0;
	virtual bool was_changed() const = 0;

	virtual ~Ival_box() {}
};

class Ival_slider : public Ival_box, protected BBwidget {
public:
	Ival_slider(int, int);
	~Ival_slider() override;

	int get_value() override;
	void set_value(int i) override;
	void reset_value(int i) override;
	// ...
protected:
	// ... functions overriding BBwidget virtual functions
	// e.g. BBwidget::draw()
private:
	// data needed for slider
};

