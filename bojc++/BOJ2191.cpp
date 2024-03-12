#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<double, double> fxy[100];
pair<double, double> txy[100];

vector<int> edge[100];
int visited[100];
int connect[100];

int func(int v)
{
	for (int nxt : edge[v])
	{
		if (visited[nxt])
			continue;
		visited[nxt] = 1;
		if (connect[nxt] < 0 || func(connect[nxt]))
		{
			connect[nxt] = v;
			return 1;
		}
	}
	return 0;
}

int bimatch(int n)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		if (func(i))
			++cnt;
	}
	return cnt;
}

int main()
{
	FASTIO();

	int n, m, s, v;
	cin >> n >> m >> s >> v;

	for (int i = 0; i < n; ++i)
		cin >> fxy[i].first >> fxy[i].second;
	for (int i = 0; i < m; ++i)
		cin >> txy[i].first >> txy[i].second;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			double dx = fxy[i].first - txy[j].first;
			double dy = fxy[i].second - txy[j].second;

			if (s * v * s * v >= dx * dx + dy * dy)
				edge[i].push_back(j);
		}
	}

	memset(connect, -1, sizeof(connect));
	cout << n - bimatch(n);
}