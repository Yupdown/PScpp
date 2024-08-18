#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

int main()
{
	FASTIO();
	PRECISION(16);

	double m[3][3];
	for (int i = 0; i < 9; ++i)
		cin >> m[i / 3][i % 3];
	double t = acos((m[0][0] + m[1][1] + m[2][2] - 1) / 2);
	double l = sin(t) * 2;
	double u[3]{ m[2][1] - m[1][2], m[0][2] - m[2][0], m[1][0] - m[0][1] };
	cout << t * 180 / M_PI << '\n' << u[0] / l << ' ' << u[1] / l << ' ' << u[2] / l;
}