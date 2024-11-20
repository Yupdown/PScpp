#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

template <typename T>
struct fraction
{
public:
	T num, den;

	fraction() : num(0), den(1) {}
	fraction(const T numerator) : num(numerator), den(1) {}
	fraction(const T numerator, const T denominator) : num(numerator), den(denominator)
	{
		if (denominator < 0)
		{
			num *= -1;
			den *= -1;
		}
	}

	fraction reduction() const
	{
		if (num == 0)
			return fraction(0);
		T a = abs(num);
		T b = den;
		while (b != 0)
		{
			T temp = a % b;
			a = b;
			b = temp;
		}
		return fraction(num / a, den / a);
	}

	fraction operator+() const { return *this; }
	fraction operator-() const { return fraction(-num, den); }
	fraction operator+(const fraction& other) const { return fraction(num * other.den + other.num * den, den * other.den).reduction(); }
	fraction operator-(const fraction& other) const { return *this + (-other); }
	fraction operator*(const fraction& other) const { return fraction(num * other.num, den * other.den).reduction(); }
	fraction operator/(const fraction& other) const { return fraction(num * other.den, den * other.num).reduction(); }
	bool operator==(const fraction& other) const { return num * other.den == other.num * den; }
	bool operator!=(const fraction& other) const { return !(*this == other); }
	bool operator<(const fraction& other) const { return num * other.den < other.num * den; }
	bool operator>(const fraction& other) const { return num * other.den > other.num * den; }
	bool operator<=(const fraction& other) const { return !(*this > other); }
	bool operator>=(const fraction& other) const { return !(*this < other); }
	fraction& operator=(const T other) { num = other; den = 1; return *this; }
	explicit operator double() const { return static_cast<double>(num) / den; }
};

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

using ivector2d = vector2d<int64>;

ivector2d pos[10000];
ivector2d dir[10000];
int64 n, l;

int main()
{
	FASTIO();

	cin >> n >> l;
	for (int i = 0; i < n; ++i)
	{
		int64 x, y, p, q;
		cin >> x >> y >> p >> q;
		pos[i] = vector2d(x, y);
		dir[i] = vector2d(p - x, q - y);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			ivector2d c = pos[j] - pos[i];
			int64 d = ivector2d::cross(dir[i], dir[j]);
			fraction<int64> t = fraction(ivector2d::cross(c, dir[j]), d);
			fraction<int64> s = fraction(ivector2d::cross(c, dir[i]), d);
			if (t < 0 || s < 0)
				continue;
		}
	}
}