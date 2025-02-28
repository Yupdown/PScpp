#include <iostream>
#include <cmath>

using namespace std;

struct vector3d
{
	double x;
	double y;
	double z;
};

double lerp(double a, double b, double t)
{
	return a + (b - a) * t;
}

vector3d lerp(vector3d a, vector3d b, double t)
{
	return { lerp(a.x, b.x, t), lerp(a.y, b.y, t), lerp(a.z, b.z, t) };
}

double dist(vector3d a, vector3d b)
{
	double dx = b.x - a.x;
	double dy = b.y - a.y;
	double dz = b.z - a.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

int main()
{
	cout.precision(10);
	cout << fixed;

	vector3d a, b, c;
	cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> c.x >> c.y >> c.z;

	double l = 0.0, h = 1.0;
	double p, q;

	while (h - l > 1.e-12)
	{
		p = (l * 2.0 + h) / 3.0;
		q = (l + h * 2.0) / 3.0;

		if (dist(lerp(a, b, p), c) < dist(lerp(a, b, q), c))
			h = q;
		else
			l = p;
	}

	cout << dist(lerp(a, b, l), c) << endl;
	return 0;
}