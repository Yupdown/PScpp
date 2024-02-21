#include <bits/stdc++.h>

using namespace std;

int prime[1 << 11];
vector<int> table[2];
vector<int> edge[25];
int visited[25];
int connect[25];
vector<int> ret;

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
	int n;
	cin >> n;

	for (int i = 0, v0; i < n; ++i)
	{
		int v;
		cin >> v;
		if (i == 0)
			v0 = v;
		table[(v0 + v) % 2].push_back(v);
	}

	for (int i = 2; i < 1 << 11; ++i)
	{
		if (prime[i])
			continue;
		for (int j = i * 2; j < 1 << 11; j += i)
			prime[j] = 1;
	}

	if (table[0].size() == table[1].size())
	{
		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = 0; j < n / 2; ++j)
			{
				if (!prime[table[0][i] + table[1][j]])
					edge[i].push_back(j);
			}
		}

		for (int i = 0; i < edge[0].size(); ++i)
		{
			memset(connect, -1, sizeof(connect));
			connect[edge[0][i]] = 0;

			int cnt = 1;
			for (int j = 1; j < n / 2; ++j)
			{
				memset(visited, 0, sizeof(visited));
				visited[edge[0][i]] = 1;
				if (func(j))
					++cnt;
			}

			if (cnt == n / 2)
				ret.push_back(table[1][edge[0][i]]);
		}
	}

	if (ret.empty())
		cout << -1;
	else
	{
		sort(ret.begin(), ret.end());
		for (int v : ret)
			cout << v << ' ';
	}
}