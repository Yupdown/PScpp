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

	vector3d operator-() const { return { -x, -y, -z }; }
	vector3d operator+(const vector3d& rhs) const { return { x + rhs.x, y + rhs.y, z + rhs.z }; }
	vector3d operator-(const vector3d& rhs) const { return *this + (-rhs); }
	vector3d operator*(const T& rhs) const { return { x * rhs, y * rhs, z * rhs }; }
	vector3d operator/(const T& rhs) const { return { x / rhs, y / rhs, z / rhs }; }
	bool operator==(const vector3d& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }
	bool operator!=(const vector3d& rhs) const { return !(*this == rhs); }
	bool operator<(const vector3d& rhs) const { if (x != rhs.x) return x < rhs.x; if (y != rhs.y) return y < rhs.y; return z < rhs.z; }
	static T dot(const vector3d& lhs, const vector3d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z; }
	T sqr_magnitude() const { return dot(*this, *this); }
};

using int64 = long long;
using vector3di = vector3d<int64>;
vector3di table[150000];

bool less_y(const vector3di& lhs, const vector3di& rhs)
{
	if (lhs.y != rhs.y) return lhs.y < rhs.y; if (lhs.x != rhs.x) return lhs.x < rhs.x; return lhs.z < rhs.z;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i].x >> table[i].y >> table[i].z;

	sort(table, table + n);
	n = distance(table, unique(table, table + n));

	set<vector3di, decltype(&less_y)> point_yxz(less_y);

	point_yxz.emplace(table[0]);
	point_yxz.emplace(table[1]);

	int64 distance_min = (table[0] - table[1]).sqr_magnitude();
	int cnt = 1;

	for (int i = 2, j = 0; i < n; ++i)
	{
		int64 sqrt_distance_min = ceil(sqrt(distance_min)) + 1;

		while (j < i)
		{
			if (table[i].x - table[j].x <= sqrt_distance_min)
				break;
			point_yxz.erase(table[j]);
			j++;
		}

		auto iterator = point_yxz.lower_bound({ 0, table[i].y - sqrt_distance_min, 0 });
		auto end = point_yxz.upper_bound({ 0, table[i].y + sqrt_distance_min, 0 });

		while (iterator != end)
		{
			int64 distance = (table[i] - *iterator++).sqr_magnitude();
			if (distance == distance_min)
				cnt++;
			else if (distance < distance_min)
			{
				cnt = 1;
				distance_min = distance;
			}
		}

		point_yxz.emplace(table[i]);
	}

	cout << distance_min << '\n' << cnt;
}