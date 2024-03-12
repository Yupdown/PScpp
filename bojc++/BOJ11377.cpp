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

	int n, m, k;
	cin >> n >> m >> k;

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

	memset(connect, -1, sizeof(connect));
	int cnt = bimatch(n);
	cnt += min(bimatch(n), k);

	cout << cnt;
}