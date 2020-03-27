struct Point {
	int x, y, z;
	constexpr Point up(int d) const { return { x, y, z + d }; }
	constexpr Point move(int dx, int dy) const { return { x + dx, y + dy }; }
};

constexpr Point origo{ 0, 0 };
constexpr int z = origo.z;
constexpr Point a[] = {
	origo, Point{ 1, 1 }, Point{ 2, 2 }, origo.move(3, 3)
};
constexpr int x = a[1].x;  // x becomes 1
constexpr Point xy{ 0, sqrt(2) };  // error: sqrt(2) is not a constexpr

constexpr int square(int x)
{
	return x * x;
}

constexpr int isqrt(int i);
constexpr int radial_distance(Point p)
{
	return isqrt(square(p.x) + square(p.y) + square(p.z));
}

constexpr Point p1{ 10, 20, 30 };  // the default constructor is constexpr
constexpr Point p2{ p1.up(20) };  // Point::up() is constexpr