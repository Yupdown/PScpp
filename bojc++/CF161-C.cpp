#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[200000];
pair<int, int> quary[100000];
int dist[200000][2];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, m;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> quary[i].first >> quary[i].second;

		memset(dist, 0, sizeof(dist));

		dist[1][0] = 1;
		for (int i = 2; i < n; ++i)
		{
			if (table[i - 1] - table[i - 2] > table[i] - table[i - 1])
				dist[i][0] = dist[i - 1][0] + 1;
			else
				dist[i][0] = dist[i - 1][0] + table[i] - table[i - 1];
		}


		dist[n - 2][1] = 1;
		for (int i = n - 3; i >= 0; --i)
		{
			if (table[i + 2] - table[i + 1] > table[i + 1] - table[i])
				dist[i][1] = dist[i + 1][1] + 1;
			else
				dist[i][1] = dist[i + 1][1] - table[i] + table[i + 1];
		}

		for (int i = 0; i < m; ++i)
		{
			if (quary[i].first < quary[i].second)
				cout << dist[quary[i].second - 1][0] - dist[quary[i].first - 1][0];
			else
				cout << dist[quary[i].second - 1][1] - dist[quary[i].first - 1][1];
			cout << '\n';
		}
	}
}