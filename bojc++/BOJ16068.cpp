#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

const double PI = 3.14159265358979;
const double DEG2RAD = PI / 180.0;
const double RADIUS_SURFACE = 6371.0;
const double M_C = 299792.458;

inline void rotate_transform(double v[3], double theta, double psi, double phi)
{
	double r[3] = {};
	double matrix[3][3] = {
		cos(theta) * cos(phi) - sin(theta) * cos(psi) * sin(phi), -sin(theta) * cos(phi) - cos(theta) * cos(psi) * sin(phi), sin(psi) * sin(phi),
		cos(theta) * sin(phi) + sin(theta) * cos(psi) * cos(phi), -sin(theta) * sin(phi) + cos(theta) * cos(psi) * cos(phi), -sin(psi) * cos(phi),
		sin(theta) * sin(psi), cos(theta) * sin(psi), cos(theta)
	};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			r[i] += matrix[i][j] * v[j];
	}

	for (int i = 0; i < 3; ++i)
		v[i] = r[i];
}

inline double dot_product(const double lhs[3], const double rhs[3])
{
	return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
}

int main()
{
	FASTIO();
	PRECISION(12);
	
	int s;
	double lo, la;

	cin >> s;
	cin >> lo >> la;

	double pos_reference[3] = { RADIUS_SURFACE * cos(la * DEG2RAD) * cos(lo * DEG2RAD), RADIUS_SURFACE * cos(la * DEG2RAD) * sin(lo * DEG2RAD), RADIUS_SURFACE * sin(la * DEG2RAD) };

	for (int i = 0; i < s; ++i) {
		double phi, psi, r, x;
		cin >> phi >> psi >> r >> x;

		double pos_satellite[3] = { r, 0.0, 0.0 };
		rotate_transform(pos_satellite, x * PI * 2.0, psi * DEG2RAD, phi * DEG2RAD);

		double delta[3] = {};
		for (int i = 0; i < 3; ++i)
			delta[i] = pos_reference[i] - pos_satellite[i];
		
		if (dot_product(pos_reference, delta) > 0.0)
			cout << "no signal\n";
		else {
			double dist = sqrt(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
			cout << dist / M_C << "\n";
		}
	}
}