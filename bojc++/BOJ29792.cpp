#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

int64 d[49];
int64 p[13];
int64 q[13];
int64 t[49][13];
int64 s[49];

int visited[1 << 13];
int64 solution(int k, int pi, int rt, int bitmask)
{
	if (visited[bitmask] > 0)
		return 0;
	visited[bitmask] = 1;

	int64 nx = 0;
	for (int ki = 0; ki < k; ++ki)
	{
		if ((bitmask >> ki) & 1)
			continue;
		if (rt >= t[pi][ki])
			nx = max(nx, solution(k, pi, rt - t[pi][ki], bitmask | 1 << ki) + q[ki]);
	}
	return nx;
}

int main()
{
	FASTIO();

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		cin >> d[i];
	for (int i = 0; i < k; ++i)
		cin >> p[i] >> q[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
			t[i][j] = (p[j] + d[i] - 1) / d[i];
	}

	for (int i = 0; i < n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		s[i] = solution(k, i, 900, 0);
	}

	sort(s, s + n);
	int64 sum = 0;
	for (int i = 0; i < m; ++i)
		sum += s[n - i - 1];
	cout << sum;
}