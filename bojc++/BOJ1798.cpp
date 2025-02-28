#include <iostream>
#include <cmath>

#define DEG2RAD ((3.14159265359 * 2.0) / 360.0)

using namespace std;

int main()
{
	double r, h, d1, a1, d2, a2;

	cout << fixed;
	cout.precision(2);

	while (cin >> r >> h >> d1 >> a1 >> d2 >> a2)
	{
		double pi = r * 360.0 / sqrt(r * r + h * h);

		a1 = a1 * pi / 360.0;
		a2 = a2 * pi / 360.0;

		double p[3][2] =
		{
			cos(a1 * DEG2RAD) * d1, sin(a1 * DEG2RAD) * d1,
			cos(a2 * DEG2RAD) * d2, sin(a2 * DEG2RAD) * d2,
			cos((a1 + pi) * DEG2RAD) * d1, sin((a1 + pi) * DEG2RAD) * d1
		};

		double dp[2][2] =
		{
			p[1][0] - p[0][0], p[1][1] - p[0][1],
			p[2][0] - p[1][0], p[2][1] - p[1][1]
		};

		double r1 = sqrt(dp[0][0] * dp[0][0] + dp[0][1] * dp[0][1]);
		double r2 = sqrt(dp[1][0] * dp[1][0] + dp[1][1] * dp[1][1]);


		cout << min(r1, r2) << endl;
	}

	return 0;
}