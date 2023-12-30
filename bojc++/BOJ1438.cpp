#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> points[100];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> points[i].first >> points[i].second;

	int hn = (n + 1) / 2;
	int result = INT_MAX;
	sort(points, points + n);

	for (int xmin = 0; xmin < n; ++xmin)
	{
		for (int xmax = xmin + hn - 1; xmax < n; ++xmax)
		{
			vector<int> y;
			for (int x = xmin; x <= xmax; ++x)
				y.push_back(points[x].second);
			sort(y.begin(), y.end());

			for (int ymin = 0; ymin + hn - 1 < y.size(); ++ymin)
			{
				int ymax = ymin + hn - 1;
				int width = points[xmax].first - points[xmin].first;
				int height = y[ymax] - y[ymin];
				result = min(result, (width + 2) * (height + 2));
			}
		}
	}

	cout << result;
}