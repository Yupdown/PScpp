#include <iostream>
#include <cmath>

using namespace std;

struct vector3d
{
	double x;
	double y;
	double z;

	double magnitude()
	{
		return sqrt(x * x + y * y + z * z);
	}

	vector3d normalize()
	{
		double v = magnitude();

		return { x / v, y / v, z / v };
	}

	static double dot(vector3d lhs, vector3d rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
	}
};

int observable(vector3d s, vector3d t, double l)
{
	return vector3d::dot(s.normalize(), t.normalize()) > cos(l);
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	vector3d star[5000], telescope[50];
	double latitude[50];

	while (cin >> n)
	{
		if (n == 0)
			break;

		for (int i = 0; i < n; ++i)
			cin >> star[i].x >> star[i].y >> star[i].z;

		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> telescope[i].x >> telescope[i].y >> telescope[i].z >> latitude[i];

		int r = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (observable(star[i], telescope[j], latitude[j]))
				{
					++r;
					break;
				}
			}
		}

		cout << r << endl;
	}

	return 0;
}