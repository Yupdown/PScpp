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

// 180 degrees is 10'800 'angles'
int stoa(string_view s)
{
	auto sep = s.find(',');
	int deg = stoi(s.substr(0, sep).data());
	int min = stoi(s.substr(sep + 1, s.size() - sep - 2).data());
	int ret = deg * 60 + min;
	switch (s.back())
	{
	case 'N':
	case 'W':
		return ret;
	case 'S':
	case 'E':
		return -ret;
	}
}

string atos(int value)
{
	char c = value < 0 ? 'S' : 'N';
	value = abs(value);
	int deg = value / 60;
	int min = value % 60;
	stringstream stream;
	stream << deg << ',' << min << c;
	return stream.str();
}

constexpr double PI = 3.14159265358979323846;
constexpr double TORAD = PI / 10800;

vector3df atov(int la, int lo)
{
	double lar = la * TORAD;
	double lor = lo * TORAD;
	double mul = cos(lar);
	return vector3df(cos(lor) * mul, sin(lor) * mul, sin(lar));
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	while (n--)
	{
		string str[4];
		for (auto& s : str)
			cin >> s;
		int angles[4];
		transform(str, str + 4, angles, stoa);
		if (angles[0] == -angles[2] && abs(angles[1] - angles[3]) == 10800)
			cout << "undefined\n";
		else if (angles[0] == angles[2] && angles[1] == angles[3])
			cout << str[0] << '\n';
		else
		{
			vector3df v1 = atov(angles[0], angles[1]);
			vector3df v2 = atov(angles[2], angles[3]);
			vector3df vn = vector3df::cross(v1, v2).normalized();
			vector3df vv = v1;
			vector3df vu = vector3df::cross(vn, vv);
			double zmax = max(v1.z, v2.z);
			if (vu.z != 0 || vv.z != 0)
			{
				double t = atan2(vu.z, vv.z);
				if (t < 0)
					t += PI;
				if (t < acos(vector3df::dot(v1, v2)))
					zmax = max(zmax, vv.z * cos(t) + vu.z * sin(t));
			}
			cout << atos(round(asin(zmax) / TORAD)) << '\n';
		}
	}
}