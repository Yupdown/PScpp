#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

template <typename T>
struct vector2d
{
    T x, y;

    vector2d() : vector2d(0, 0) {}
    vector2d(T x, T y) : x(x), y(y) {}
    vector2d(const vector2d& rhs) : x(rhs.x), y(rhs.y) {}
    template <typename TR>
    vector2d(const vector2d<TR>& rhs) : x(static_cast<T>(rhs.x)), y(static_cast<T>(rhs.y)) {}

    T sqr_magnitude() const { return x * x + y * y; }
    T magnitude() const { return sqrt(sqr_magnitude()); }
    static T dot(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
    static T cross(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }

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
    bool operator<(const vector2d& other) const { return x < other.x || (x == other.x && y < other.y); }
    bool operator>(const vector2d& other) const { return x > other.x || (x == other.x && y > other.y); }
    bool operator<=(const vector2d& other) const { return x <= other.x && y <= other.y; }
    bool operator>=(const vector2d& other) const { return x >= other.x && y >= other.y; }
};

double volume(double a, double b, double c)
{
    pair<double, vector2d<double>> p[3];
    p[0] = { a, vector2d<double>(0, 0) };
    p[1] = { b, vector2d<double>(1, 0) };
    p[2] = { c, vector2d<double>(0, 1) };
    sort(p, p + 3);
    int pos = distance(p, find_if(p, p + 3, [](const auto& v) { return v.first >= 0; }));
    switch (pos)
    {
    case 0:
        return (a + b + c) / 6;
    case 1:
        for (int i = 0; i < 3; ++i)
            p[i].first *= -1;
        break;
    case 2:
        reverse(p, p + 3);
        break;
    case 3:
        return 0;
    }

    double td = p[0].first / (p[0].first - p[1].first);
    double te = p[0].first / (p[0].first - p[2].first);
    vector2d<double> d = p[0].second * (1 - td) + p[1].second * td;
    vector2d<double> e = p[0].second * (1 - te) + p[2].second * te;
    double v = abs(vector2d<double>::cross(d - p[0].second, e - p[0].second)) / 6 * p[0].first;
    if (pos == 1)
        v = (a + b + c) / 6 + v;
    return v;
}

double table[100][100];

int main()
{
	FASTIO();
	PRECISION(12);

	int t;
	cin >> t;
	while (t--)
	{
		int r, c, l;
		cin >> r >> c >> l;
		for (int i = 0; i < r * c; ++i)
		{
			int h;
			cin >> h;
			table[i / c][i % c] = static_cast<double>(h - l) * 1e-2;
		}
		double ret = 0;
		for (int i = 0; i < r - 1; ++i)
		{
			for (int j = 0; j < c - 1; ++j)
				ret += volume(table[i][j], table[i + 1][j], table[i][j + 1]) + volume(table[i + 1][j + 1], table[i + 1][j], table[i][j + 1]);
		}
		cout << ret << '\n';
	}
}