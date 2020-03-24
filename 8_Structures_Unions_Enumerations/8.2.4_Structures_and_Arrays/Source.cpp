#include <iostream>
using namespace std;


struct Point {
	int x, y;
};
Point points[3]{ { 1, 2 }, { 3, 4 }, { 5, 6 } };
int x2 = points[2].x;

struct Array {
	Point elem[3];
};
Array points2{ {1, 2}, {3, 4}, {5, 6} };
int y2 = points2.elem[2].y;

Array shift(Array a, Point p)
{
	for (int i = 0; i != 3; ++i) {
		a.elem[i].x += p.x;
		a.elem[i].y += p.y;
	}
	return a;
}
Array ax = shift(points2, { 10, 20 });

template<typename T, size_t N>
struct array {
	T elem[N];

	T* begin() noexcept { return elem; }
	const T* begin() const noexcept { return elem; }
	T* end() noexcept { return elem + N; }
	const T* end() const noexcept { return elem + N; };

	constexpr size_t size() noexcept { return N; }

	T& operator[](size_t n) { return elem[n]; }
	const T& operator[](size_t n) const { return elem[n]; }

	T* data() noexcept { return elem; }
	const T* data() const noexcept { return elem; }
};
using Array = array<Point, 3>;  // array of 3 Points
Array points3{ {1, 2}, { 3, 4 }, { 5, 6 } };
int x2 = points3[2].x;
int y2 = points3[2].y;

template<typename T, size_t N>
array<T, N> shift(array<T, N> a, Point p)
{
	for (int i = 0; i != a.size(); ++i) {
		a[i].x += p.x;
		a[i].y += p.y;
	}
	return a;
}
Array ax = shift(points3, { 10, 20 });

ostream& operator<<(ostream& os, Point p)
{
	return cout << '{' << p.x << ", " << p.y << '}';
}

void print(Point a[], int s)  // must specify number of elements
{
	for (int i = 0; i != s; ++i)
		cout << a[i] << '\n';
}

template <typename T, size_t N>
void print(array<T, N>& a)
{
	for (int i = 0; i != a.size(); ++i)
		cout << a[i] << '\n';
}

Point point1[] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };  // 3 elements
array<Point, 3> point2 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };  // 3 elements
array<Point> point3 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };  // error: number of elements not given

void f()
{
	print(point1, 4);  // 4 is a bad error
	print(point2);
}
