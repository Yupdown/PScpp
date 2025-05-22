#include <bits/stdc++.h>
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

template <typename T>
struct vector2d
{
    T x, y;
    vector2d() = default;
    vector2d(T x, T y) : x(x), y(y) {}

    T sqr_magnitude() const { return x * x + y * y; }
    double magnitude() const { return sqrt(sqr_magnitude()); }
    vector2d normalized() const { return *this / magnitude(); }
    vector2d operator+(const vector2d& other) const { return vector2d(x + other.x, y + other.y); }
    vector2d operator-(const vector2d& other) const { return vector2d(x - other.x, y - other.y); }
    vector2d operator+() const { return vector2d(x, y); }
    vector2d operator-() const { return vector2d(-x, -y); }
    vector2d operator*(const T& scalar) const { return vector2d(x * scalar, y * scalar); }
    vector2d operator/(const T& scalar) const { return vector2d(x / scalar, y / scalar); }
    vector2d& operator+=(const vector2d& other) { x += other.x; y += other.y; return *this; }
    vector2d& operator-=(const vector2d& other) { x -= other.x; y -= other.y; return *this; }
    vector2d& operator*=(const T& scalar) { x *= scalar; y *= scalar; return *this; }
    vector2d& operator/=(const T& scalar) { x /= scalar; y /= scalar; return *this; }
    bool operator==(const vector2d& other) const { return x == other.x && y == other.y; }
    bool operator!=(const vector2d& other) const { return x != other.x || y != other.y; }
};

template <typename T>
struct vector3d
{
	T x, y, z;
	vector3d() : vector3d(0, 0, 0) {}
	vector3d(T x, T y, T z) : x(x), y(y), z(z) {}

    T sqr_magnitude() const { return dot(*this, *this); }
    double magnitude() const { return sqrt(sqr_magnitude()); }
    vector3d normalized() const { return *this / magnitude(); }
	vector3d operator-() const { return { -x, -y, -z }; };
	vector3d operator+(const vector3d& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z }; };
	vector3d operator-(const vector3d& rhs) const { return *this + (-rhs); };
	vector3d operator*(const T& rhs) const { return { x * rhs, y * rhs, z * rhs }; };
	vector3d operator/(const T& rhs) const { return { x / rhs, y / rhs, z / rhs }; };
	bool operator==(const vector3d& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; };
	bool operator!=(const vector3d& rhs) const { return !(*this == rhs); };

	static T dot(const vector3d& lhs, const vector3d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }
	static vector3d cross(const vector3d& lhs, const vector3d& rhs) { return { lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x }; }
};

using int64 = long long;
using vector2di = vector2d<int64>;
using vector3di = vector3d<int64>;
using vector2df = vector2d<double>;
using vector3df = vector3d<double>;

template <typename T>
T ccw(const vector2d<T>& lhs, const vector2d<T>& rhs)
{
    return lhs.x * rhs.y - lhs.y * rhs.x;
}

double get_area(double x00, double x01, double x10, double x11, double yd, double zd)
{
    vector3df p0(x00, 0, 0);
    vector3df p1(x01, 0, 0);
    vector3df p2(x10, yd, zd);
    vector3df p3(x11, yd, zd);
    return (vector3df::cross(p2 - p0, p1 - p0).magnitude() + vector3df::cross(p2 - p3, p1 - p3).magnitude()) * 0.5;
}

double xlerp(double xl, double xr, double yl, double yr, double y)
{
    double t = (y - yl) / (yr - yl);
    return (1 - t) * xl + t * xr;
}

int main()
{
	PRECISION(4);

	int n;
	while (cin >> n && n)
	{
		vector<vector2di> points;
		for (int i = 0; i < n; ++i)
		{
			auto& p = points.emplace_back();
			cin >> p.x >> p.y;
		}
        // rotate the vector so that the first element becomes the bottom point
        auto comp = [](const auto& lhs, const auto& rhs) { return lhs.y < rhs.y; };
        rotate(points.begin(), min_element(points.begin(), points.end(), comp), points.end());
        auto pb = points.begin();
        auto pt = max_element(points.begin(), points.end(), comp);
        double ret = 0;

        // if the prism is triangular
        if (n == 3)
        {
            double xl, xr, zm;
            if (pt - pb == 1)
            {
                zm = points[2].y;
                xl = xlerp(pb->x, pt->x, pb->y, pt->y, zm);
                xr = points[2].x;
            }
            else
            {
                zm = points[1].y;
                xl = points[1].x;
                xr = xlerp(pb->x, pt->x, pb->y, pt->y, zm);
            }
            ret += get_area(pb->x, pb->x, xl, xr, xl - pb->x, zm - pb->y) + get_area(pb->x, pb->x, xl, xr, xr - pb->x, zm - pb->y);
            ret += get_area(xl, xr, pt->x, pt->x, xl - pt->x, pt->y - zm) + get_area(xl, xr, pt->x, pt->x, xr - pt->x, pt->y - zm);
        }

        // if the prism is quadrangular
        else
        {
            // if the side points are on the other side
            if (pt - pb == 2)
            {
                if (points[1].y > points[3].y)
                    swap(points[1], points[3]);
                double x0l = points[1].x;
                double x0r = xlerp(pb->x, points[3].x, pb->y, points[3].y, points[1].y);
                double x1l = xlerp(points[1].x, pt->x, points[1].y, pt->y, points[3].y);
                double x1r = points[3].x;
                ret += get_area(pb->x, pb->x, x0l, x0r, x0l - pb->x, points[1].y - pb->y) + get_area(pb->x, pb->x, x0l, x0r, x0r - pb->x, points[1].y - pb->y);
                ret += get_area(x0l, x0r, x1l, x1r, x1l - x0l, points[3].y - points[1].y) + get_area(x0l, x0r, x1l, x1r, x1r - x0r, points[3].y - points[1].y);
                ret += get_area(x1l, x1r, pt->x, pt->x, x1l - pt->x, pt->y - points[3].y) + get_area(x1l, x1r, pt->x, pt->x, x1r - pt->x, pt->y - points[3].y);
            }
            // if the side points are on the same side
            else
            {
                // reordering points so that the side points are points[1], points[2] and the top points is points[3]
                if (pt - pb == 1)
                {
                    reverse(points.begin() + 1, points.end());
                    pt = points.begin() + 3;
                }
                // if the side points are y-ordered
                if (points[1].y <= points[2].y)
                {
                    double x0l = points[1].x;
                    double x0r = xlerp(pb->x, pt->x, pb->y, pt->y, points[1].y);
                    double x1l = points[2].x;
                    double x1r = xlerp(pb->x, pt->x, pb->y, pt->y, points[2].y);
                    ret += get_area(pb->x, pb->x, x0l, x0r, x0l - pb->x, points[1].y - pb->y) + get_area(pb->x, pb->x, x0l, x0r, x0r - pb->x, points[1].y - pb->y);
                    ret += get_area(x0l, x0r, x1l, x1r, x1l - x0l, points[2].y - points[1].y) + get_area(x0l, x0r, x1l, x1r, x1r - x0r, points[2].y - points[1].y);
                    ret += get_area(x1l, x1r, pt->x, pt->x, x1l - pt->x, pt->y - points[2].y) + get_area(x1l, x1r, pt->x, pt->x, x1r - pt->x, pt->y - points[2].y);
                }
                // if there aren't, the worst nightmare you've never seen has begun
                else
                {
                    // if the polygon is lower hollow, reverse the order and let assume the first point is the top point
                    if (ccw(*pt - *pb, points[1] - *pb) * ccw(points[1] - *pb, points[2] - *pb) > 0)
                    {
                        reverse(points.begin(), points.end());
                        pb = points.begin();
                        pt = points.begin() + 3;
                    }
                    double x0l = xlerp(pb->x, points[1].x, pb->y, points[1].y, points[2].y);
                    double x0r = xlerp(pb->x, pt->x, pb->y, pt->y, points[2].y);
                    double x1l = xlerp(points[2].x, pt->x, points[2].y, pt->y, points[1].y);
                    double x1r = xlerp(pb->x, pt->x, pb->y, pt->y, points[1].y);

                    ret += get_area(pb->x, pb->x, x0l, x0r, x0l - pb->x, points[2].y - pb->y) + get_area(pb->x, pb->x, x0l, x0r, x0r - pb->x, points[2].y - pb->y);
                    ret += get_area(points[2].x, x0r, pt->x, pt->x, points[2].x - pt->x, pt->y - points[2].y) + get_area(points[2].x, x0r, pt->x, pt->x, x0r - pt->x, pt->y - points[2].y);
                    ret += get_area(x0l, points[2].x, points[1].x, points[1].x, points[1].x - points[2].x, points[1].y - points[2].y) + get_area(x0l, points[2].x, points[1].x, points[1].x, points[1].x - x0l, points[1].y - points[2].y);
                    ret += get_area(x0l, points[2].x, points[1].x, points[1].x, x1l - points[2].x, points[1].y - points[2].y) + get_area(x0l, points[2].x, points[1].x, points[1].x, x1r - x0r, points[1].y - points[2].y);
                    ret += get_area(points[2].x, x0r, x1l, x1r, points[1].x - x0l, points[1].y - points[2].y) + get_area(points[2].x, x0r, x1l, x1r, points[1].x - points[2].x, points[1].y - points[2].y);
                }
            }
        }
        cout << ret * 2 << "\n";
	}
}