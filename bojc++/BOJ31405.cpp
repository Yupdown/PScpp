#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

pair<double, double> xy[200000];
double sum[200000];

double cross_product(double ax, double ay, double bx, double by)
{
	return ax * by - bx * ay;
}

double get_size(double ax, double ay, double bx, double by, double cx, double cy)
{
	return abs(cross_product(bx - ax, by - ay, cx - ax, cy - ay));
}

int main()
{
	FASTIO();
	PRECISION(15);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> xy[i].first >> xy[i].second;

	cout << "YES" << endl;
	cout << 1 << ' ' << 0.0 << endl;

	for (int i = 1; i < n; ++i)
		sum[i] = sum[i - 1] + get_size(xy[0].first, xy[0].second, xy[i - 1].first, xy[i - 1].second, xy[i].first, xy[i].second);

	double whole_sum = sum[n - 1];

	int target = n - 1;
	for (int i = 1; i < n; ++i)
	{
		if (sum[i - 1] < whole_sum / 2 && sum[i] >= whole_sum / 2)
		{
			target = i;
			break;
		}
	}

	double tf = 0;
	double tt = 1;
	for (int i = 0; i < 100; ++i)
	{
		double tm = (tf + tt) / 2;
		double xp = xy[target - 1].first + (xy[target].first - xy[target - 1].first) * tm;
		double yp = xy[target - 1].second + (xy[target].second - xy[target - 1].second) * tm;

		double s = get_size(xy[0].first, xy[0].second, xy[target - 1].first, xy[target - 1].second, xp, yp);

		if (sum[target - 1] + s < whole_sum / 2)
			tf = tm;
		else
			tt = tm;
	}

	cout << target << ' ' << tf;
}