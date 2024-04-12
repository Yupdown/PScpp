#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

struct vector3d
{
	double x, y, z;

	vector3d() : vector3d(0, 0, 0) {}
	vector3d(double x, double y, double z) : x(x), y(y), z(z) {}

	vector3d operator+(const vector3d& other) const { return vector3d(x + other.x, y + other.y, z + other.z); }
	vector3d operator-(const vector3d& other) const { return vector3d(x - other.x, y - other.y, z - other.z); }
	vector3d operator+() const { return vector3d(x, y, z); }
	vector3d operator-() const { return vector3d(-x, -y, -z); }
	vector3d operator*(const double& scalar) const { return vector3d(x * scalar, y * scalar, z * scalar); }
	vector3d operator/(const double& scalar) const { return vector3d(x / scalar, y / scalar, z / scalar); }
	vector3d& operator+=(const vector3d& other) { x += other.x; y += other.y; z += other.z; return *this; }
	vector3d& operator-=(const vector3d& other) { x -= other.x; y -= other.y; z -= other.z; return *this; }
	vector3d& operator*=(const double& scalar) { x *= scalar; y *= scalar; z *= scalar; return *this; }
	vector3d& operator/=(const double& scalar) { x /= scalar; y /= scalar; z /= scalar; return *this; }
};
vector3d table[1000];

double sqr_length(const vector3d& v)
{
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

double sqr_dist(const vector3d& lhs, const vector3d& rhs)
{
	return sqr_length(lhs - rhs);
}

double dot_product(const vector3d& lhs, const vector3d& rhs)
{
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

vector3d cross_product(const vector3d& lhs, const vector3d& rhs)
{
	return vector3d(
		lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.x * rhs.y - lhs.y * rhs.x
	);
}

vector3d circumcenter(const vector3d& a, const vector3d& b)
{
	return (a + b) / 2.0;
}

vector3d circumcenter(const vector3d& a, const vector3d& b, const vector3d& c)
{
	vector3d av = a - c;
	vector3d bv = b - c;
	vector3d abcross = cross_product(av, bv);
	vector3d p = cross_product((bv * sqr_length(av) - av * sqr_length(bv)), abcross) / (sqr_length(abcross) * 2.0);
	return c + p;
}

vector3d circumcenter(const vector3d& a, const vector3d& b, const vector3d& c, const vector3d& d)
{
	vector3d ba = b - a;
	vector3d ca = c - a;
	vector3d da = d - a;

	double len_ba = sqr_length(ba);
	double len_ca = sqr_length(ca);
	double len_da = sqr_length(da);

	vector3d cross_cd = cross_product(ca, da);
	vector3d cross_db = cross_product(da, ba);
	vector3d cross_bc = cross_product(ba, ca);

	double denominator = 0.5 / dot_product(ba, cross_cd);
	return a + vector3d(
		len_ba * cross_cd.x + len_ca * cross_db.x + len_da * cross_bc.x,
		len_ba * cross_cd.y + len_ca * cross_db.y + len_da * cross_bc.y,
		len_ba * cross_cd.z + len_ca * cross_db.z + len_da * cross_bc.z
	) * denominator;
}

int main()
{
	FASTIO();
	PRECISION(2);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i].x >> table[i].y >> table[i].z;
	for (int i = 0; i < n; ++i)
		swap(table[i], table[rand() % n]);

	vector3d p;
	double rr = 0;

	for (int i = 0; i < n; ++i)
	{
		if (sqr_dist(p, table[i]) > rr)
		{
			p = table[i];
			rr = 0;
			for (int j = 0; j < i; ++j)
			{
				if (sqr_dist(p, table[j]) > rr)
				{
					p = circumcenter(table[i], table[j]);
					rr = sqr_dist(p, table[i]);
					for (int k = 0; k < j; ++k)
					{
						if (sqr_length(cross_product(table[i] - table[k], table[j] - table[k])) == 0)
							continue;
						if (sqr_dist(p, table[k]) > rr)
						{
							p = circumcenter(table[i], table[j], table[k]);
							rr = sqr_dist(p, table[i]);
							for (int l = 0; l < k; ++l)
							{
								if (dot_product(cross_product(table[i] - table[k], table[j] - table[k]), table[l] - table[k]) == 0)
									continue;
								if (sqr_dist(p, table[l]) > rr)
								{
									p = circumcenter(table[i], table[j], table[k], table[l]);
									rr = sqr_dist(p, table[i]);
								}
							}
						}
					}
				}
			}
		}
	}

	cout << sqrt(rr);
}