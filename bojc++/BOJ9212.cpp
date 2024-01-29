#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

struct v3
{
	double x, y, z;

	v3 operator-() const
	{
		return { -x, -y, -z };
	}

	v3 operator+(const v3& v) const
	{
		return { x + v.x, y + v.y, z + v.z };
	}

	v3 operator-(const v3& v) const
	{
		return *this + (-v);
	}

	double magnitude() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	v3 normalized() const
	{
		double m = magnitude();
		return { x / m, y / m, z / m };
	}
};

inline double dot_product(const v3& lhs, const v3& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

inline v3 cross_product(const v3& lhs, const v3& rhs)
{
	return { lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x };
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		v3 v1[3], v2[3];
		for (int i = 0; i < 3; ++i)
			cin >> v1[i].x >> v1[i].y >> v1[i].z;
		for (int i = 0; i < 3; ++i)
			cin >> v2[i].x >> v2[i].y >> v2[i].z;

		v3 n1 = cross_product(v1[1] - v1[0], v1[2] - v1[0]).normalized();
		v3 n2 = cross_product(v2[1] - v2[0], v2[2] - v2[0]).normalized();
		double d1 = -dot_product(n1, v1[0]);
		double d2 = -dot_product(n2, v2[0]);
		v3 dl = cross_product(n1, n2);

		double dv1[3], dv2[3];
		for (int i = 0; i < 3; ++i)
		{
			dv1[i] = dot_product(n2, v1[i]) + d2;
			dv2[i] = dot_product(n1, v2[i]) + d1;
		}

		bool flag = true;
		for (int i = 1; i < 3; ++i)
			flag &= dv1[0] * dv1[i] >= 0 && dv2[0] * dv2[i] >= 0;

		if (!flag)
		{
			double pv1[3], pv2[3];
			for (int i = 0; i < 3; ++i)
			{
				pv1[i] = dot_product(dl, v1[i]);
				pv2[i] = dot_product(dl, v2[i]);
			}

			constexpr double INF = numeric_limits<double>::infinity();
			pair<double, double> t1r{ INF, -INF }, t2r{ INF, -INF };
			for (int i = 0; i < 3; ++i)
			{
				double dv10 = dv1[i];
				double dv11 = dv1[(i + 1) % 3];
				double pv10 = pv1[i];
				double pv11 = pv1[(i + 1) % 3];
				if (dv10 != dv11 && dv10 * dv11 <= 0)
				{
					double t1 = pv10 + (pv11 - pv10) * dv10 / (dv10 - dv11);
					t1r.first = min(t1r.first, t1);
					t1r.second = max(t1r.second, t1);
				}

				double dv20 = dv2[i];
				double dv21 = dv2[(i + 1) % 3];
				double pv20 = pv2[i];
				double pv21 = pv2[(i + 1) % 3];
				if (dv20 != dv21 && dv20 * dv21 <= 0)
				{
					double t2 = pv20 + (pv21 - pv20) * dv20 / (dv20 - dv21);
					t2r.first = min(t2r.first, t2);
					t2r.second = max(t2r.second, t2);
				}
			}

			if (t1r.first >= t2r.second)
				flag = true;
			else if (t1r.second <= t2r.first)
				flag = true;
			else if (t1r.first >= t2r.first && t1r.second <= t2r.second)
				flag = true;
			else if (t1r.first <= t2r.first && t1r.second >= t2r.second)
				flag = true;
		}

		cout << (flag ? "NO" : "YES") << '\n';
	}
}