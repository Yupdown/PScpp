#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

pair<int, int> xy[100];
pair<int, int> xz[100];

double xyh[201];
double xzh[201];

pair<int, int> height_map(int n, pair<int, int>* src, double* dst)
{
	sort(src, src + n);

	int x1 = src[0].first;
	int y1 = src[0].second;
	int x2 = src[n - 1].first;
	int y2 = src[n - 1].second;

	vector<pair<int, int>> upper, lower;
	upper.push_back(src[0]);
	lower.push_back(src[0]);
	for (int i = 1; i < n - 1; ++i)
	{
		int x = src[i].first;
		int y = src[i].second;

		if ((y2 - y1) * (x - x1) + y1 * (x2 - x1) < y * (x2 - x1))
			upper.push_back(src[i]);
		else
			lower.push_back(src[i]);
	}

	if (upper.back().first < src[n - 1].first)
		upper.push_back(src[n - 1]);
	if (lower.back().first < src[n - 1].first)
		lower.push_back(src[n - 1]);

	for (int i = 0; i < upper.size() - 1; ++i)
	{
		int xf = upper[i].first;
		int yf = upper[i].second;
		int xt = upper[i + 1].first;
		int yt = upper[i + 1].second;

		for (int x = xf; x < xt; ++x)
			dst[x + 100] += yf + (yt - yf) * (x - xf) / static_cast<double>(xt - xf);
	}
	for (int i = 0; i < lower.size() - 1; ++i)
	{
		int xf = lower[i].first;
		int yf = lower[i].second;
		int xt = lower[i + 1].first;
		int yt = lower[i + 1].second;

		for (int x = xf; x < xt; ++x)
			dst[x + 100] -= yf + (yt - yf) * (x - xf) / static_cast<double>(xt - xf);
	}
	dst[src[n - 1].first + 100] = upper.back().second - lower.back().second;

	return make_pair(x1, x2);
}

int main()
{
	FASTIO();
	PRECISION(10);

	int n, m;
	cin >> n >> m;

	while (n || m)
	{
		for (int i = 0; i < n; ++i)
			cin >> xy[i].first >> xy[i].second;
		for (int i = 0; i < m; ++i)
			cin >> xz[i].first >> xz[i].second;

		memset(xyh, 0, sizeof(xyh));
		memset(xzh, 0, sizeof(xzh));

		pair<int, int> xyft = height_map(n, xy, xyh);
		pair<int, int> xzft = height_map(m, xz, xzh);

		double v = 0;
		for (int x = max(xyft.first, xzft.first) + 100; x < min(xyft.second, xzft.second) + 100; ++x)
		{
			double y1 = xyh[x];
			double z1 = xzh[x];
			double dy = xyh[x + 1] - y1;
			double dz = xzh[x + 1] - z1;
			v += y1 * z1 + dy * z1 / 2 + dz * y1 / 2 + dy * dz / 3;
		}
		cout << v << '\n';

		cin >> n >> m;
	}
}