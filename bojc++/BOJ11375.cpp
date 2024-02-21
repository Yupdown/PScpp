#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edge[1000];
int visited[1000];
int connect[1000];

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

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		int j;
		cin >> j;

		while (j-- > 0)
		{
			int v;
			cin >> v;
			edge[i].push_back(v - 1);
		}
	}

	int cnt = 0;
	memset(connect, -1, sizeof(connect));
	for (int i = 0; i < n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		if (func(i))
			++cnt;
	}

	cout << cnt;
}