#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[200000];
pair<int, long long> yp[400000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i] >> table[i];
	for (int i = 0; i < m; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u = table[u - 1];
		v = table[v - 1];
		if (u > v)
			swap(u, v);
		yp[i * 2] = { u, -c };
		yp[i * 2 + 1] = { v, c };
	}
	sort(yp, yp + m * 2);
	long long v = 0, vmax = 0;
	for (int i = 0; i < m * 2; ++i)
	{
		v -= yp[i].second;
		vmax = max(vmax, v);
	}
	cout << vmax;
}