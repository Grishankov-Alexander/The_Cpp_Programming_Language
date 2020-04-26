

class Storable {};
class Component : public virtual Storable {};
class Receiver : public Component {};
class Transmitter : public Component {};
class Radio : public Receiver, public Transmitter {};
//-------------------Storable-------------------
//----Component-------------------Component-----
//----Receiver-------------------Transmitter----
//-------------------Radio----------------------

void h1(Radio& r)
{
	Storable* ps = &r;  // OK, has unique storable
	Component* pc = dynamic_cast<Component*>(ps);  // pc = 0; Radio has 2 components
}