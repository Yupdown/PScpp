#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[1001][30];
pair<int, int> edge[1001];
char dir[500];

int main()
{
	FASTIO();

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		cin >> edge[i + 1].first >> edge[i + 1].second;
	for (int i = 0; i < m; ++i)
		cin >> dir[i];
	for (int i = 0; i < n; ++i)
	{
		int node = i + 1;
		for (int j = 0; j < m; ++j)
			node = dir[j] == 'L' ? edge[node].first : edge[node].second;
		memo[i + 1][0] = node;
	}
	for (int i = 1; i < 30; ++i)
	{
		for (int j = 0; j < n; ++j)
			memo[j + 1][i] = memo[memo[j + 1][i - 1]][i - 1];
	}
	int ret = 1;
	for (int i = 0; i < 30; ++i)
	{
		if (k >> i & 1)
			ret = memo[ret][i];
	}
	cout << ret;
}