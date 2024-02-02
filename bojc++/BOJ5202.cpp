#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
constexpr int SAMPLES = 1024;

double get_overlap(double r, double x, double y)
{
	if (x >= r)
	{
		if (y >= r)
			return r * r * M_PI * 0.5;
		double t = asin(y / r);
		return t * r * r + y * r * cos(t);
	}

	double t = acos(x / r);
	if (y >= r)
		return x * r * sin(t) + (M_PI - t * 2) * r * r / 2;

	double tp = acos(y / r);
	if (t + tp >= M_PI * 0.5)
		return x * y * 2;

	return x * r * sin(t) + y * r * sin(tp) + (M_PI - (t + tp) * 2) * r * r / 2;
}

int main()
{
	FASTIO();
	PRECISION(2);

	int k;
	cin >> k;
	
	for (int i = 0; i < k; ++i)
	{
		double w, h, r, d, a1, a2;
		cin >> w >> h >> r >> d >> a1 >> a2;

		double ret = 0;
		for (int c = 0; c < SAMPLES; ++c)
		{
			double t = tan((a1 + (a2 - a1) * (c / static_cast<double>(SAMPLES - 1))) * M_PI / 180);
			double dist = d / t;
			double sp = 0;
			sp += get_overlap(r, w * 0.5, max(0.0, h * 0.5 - dist));
			sp -= get_overlap(r, w * 0.5, max(0.0, -h * 0.5 - dist));
			sp += get_overlap(r, w * 0.5, max(0.0, h * 0.5 + dist));
			sp -= get_overlap(r, w * 0.5, max(0.0, -h * 0.5 + dist));
			ret += 1 - sp / (w * h);
		}
		cout << "Data Set " << i + 1 << ":\n" << ret * 100 / SAMPLES << "%\n";
	}
}