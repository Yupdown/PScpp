#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> dist[2];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		dist[v > 0].push_back(abs(v));
	}

	vector<int> points;
	auto callback = [&points, m](vector<int>& v) {
			sort(v.begin(), v.end());
			while (!v.empty())
			{
				points.push_back(v.end()[-1]);
				for (int i = 0; i < m && !v.empty(); ++i)
					v.pop_back();
			}
		};

	callback(dist[0]);
	callback(dist[1]);

	int vsum = 0;
	int vmax = 0;
	for (int point : points)
	{
		vsum += point;
		vmax = max(vmax, point);
	}

	cout << vsum * 2 - vmax;
}