#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

template <typename T>
struct vector3d
{
	T x, y, z;

	vector3d() : vector3d(0, 0, 0) {}
	vector3d(T x, T y, T z) : x(x), y(y), z(z) {}
	template <typename TR>
	vector3d(const vector3d<TR>& rhs) : x(static_cast<T>(rhs.x)), y(static_cast<T>(rhs.y)), z(static_cast<T>(rhs.z)) {}

	vector3d operator-() const { return { -x, -y, -z }; };
	vector3d operator+(const vector3d& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z }; };
	vector3d operator-(const vector3d& rhs) const { return *this + (-rhs); };
	vector3d operator*(const T& rhs) const { return { x * rhs, y * rhs, z * rhs }; };
	vector3d operator/(const T& rhs) const { return { x / rhs, y / rhs, z / rhs }; };
	bool operator==(const vector3d& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; };
	bool operator!=(const vector3d& rhs) const { return !(*this == rhs); };

	static T dot(const vector3d& lhs, const vector3d& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}

	static vector3d cross(const vector3d& lhs, const vector3d& rhs)
	{
		return { lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x };
	}

	double magnitude() const
	{
		return sqrt(sqr_magnitude());
	}

	T sqr_magnitude() const
	{
		return dot(*this, *this);
	}

	vector3d normalized() const
	{
		return *this / magnitude();
	}
};

using vector3df = vector3d<double>;
constexpr double EPS = 1e-5;

int main()
{
	FASTIO();

	int n;
	cin >> n;
	double d;
	cin >> d;
	vector3df vx, vy, vz;
	cin >> vx.x >> vx.y >> vx.z;
	cin >> vy.x >> vy.y >> vy.z;
	vz = vector3df::cross(vx, vy).normalized();
	vy = vector3df::cross(vz, vx).normalized();
	vx = vx.normalized();
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		vector3df p, v;
		cin >> p.x >> p.y >> p.z;
		cin >> v.x >> v.y >> v.z;
		p = p - v * d;
		p = vector3df(vector3df::dot(p, vx), vector3df::dot(p, vy), vector3df::dot(p, vz));
		if (abs(p.z) < EPS && abs(p.sqr_magnitude() - d * d) < EPS)
			ret++;
	}
	cout << ret;
}