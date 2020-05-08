

class Shape {};
class Circle : public Shape {};

template<typename T>
class Ptr {  // T* handle
	T* p;
public:
	Ptr(T* pp) : p{ pp } {}
	Ptr(const Ptr& ptr) : p{ new T{ *ptr.p } } {}  // point to new T
	template<typename T2>
	explicit operator Ptr<T2>();
};

template<typename T>
template<typename T2>
Ptr<T>::operator Ptr<T2>()
{
	return Ptr<T2>(p);
}

void f(Ptr<Circle> pc)
{
	Ptr<Shape> ps{ pc };  // OK: can convert Circle* to Shape*
	Ptr<Circle> pc2{ ps };  // error
}