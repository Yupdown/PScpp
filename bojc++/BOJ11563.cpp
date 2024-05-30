#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

struct vector2d
{
	double x, y;
	double length() const { return sqrt(x * x + y * y); };
	static double dot(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
	static double cross(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }
	vector2d operator+(const vector2d& rhs) const { return vector2d{ x + rhs.x, y + rhs.y }; };
	vector2d operator-() const { return vector2d{ -x, -y }; };
	vector2d operator-(const vector2d& rhs) const { return *this + (-rhs); };
};

double distance(const vector2d& a, const vector2d& b, const vector2d& p)
{
	if (vector2d::dot(b - a, p - a) <= 0)
		return (p - a).length();
	if (vector2d::dot(a - b, p - b) <= 0)
		return (p - b).length();
	return abs(vector2d::cross(b - a, p - a)) / (b - a).length();
}

vector2d table[2000][4];

int main()
{
	FASTIO();
	PRECISION(16);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i][0].x >> table[i][0].y >> table[i][1].x >> table[i][1].y;
	for (int i = 0; i < m; ++i)
		cin >> table[i][2].x >> table[i][2].y >> table[i][3].x >> table[i][3].y;

	double vmin = 1e+9;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			vmin = min(vmin, distance(table[i][0], table[i][1], table[j][2]));
			vmin = min(vmin, distance(table[i][0], table[i][1], table[j][3]));
			vmin = min(vmin, distance(table[j][2], table[j][3], table[i][0]));
			vmin = min(vmin, distance(table[j][2], table[j][3], table[i][1]));
		}
	}

	cout << vmin;
}