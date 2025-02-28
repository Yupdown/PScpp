#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << fixed;
	cout.precision(12);

	int x, y, d, t;
	cin >> x >> y >> d >> t;

	double dist = sqrt(x * x + y * y);
	double span = floor(dist / d) * t;

	double dist_e = dist - floor(dist / d) * d;
	span += min(t + abs(dist_e - d), dist_e);

	cout << (d > t ? min(span, max(ceil(dist / d), 2.0) * t) : dist) << endl;
	return 0;
}