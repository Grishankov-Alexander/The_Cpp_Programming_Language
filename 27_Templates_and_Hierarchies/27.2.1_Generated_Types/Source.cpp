
class Shape { public: void draw() const; };
class Circle : public Shape {};

void maul(Shape* p, int n)  // Danger!
{
	for (int i = 0; i != n; ++i)
		p[i].draw();  // looks innocent but disaster
}

void user()
{
	Circle image[10];  // an image of 10 circles
	maul(image, 10);  // Circle [10] -> Circle* -> Shape*
}