#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int dir[100];
int cnt[100];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	iota(dir, dir + 100, 0);
	for (int i = 0; i < n + m; ++i)
	{
		int u, v;
		cin >> u >> v;
		dir[u - 1] = v - 1;
	}

	memset(cnt, -1, sizeof(cnt));
	cnt[0] = 0;

	queue<int> nxt;
	nxt.push(0);

	while (!nxt.empty())
	{
		int cur = nxt.front();
		nxt.pop();

		for (int v = 1; v <= 6; ++v)
		{
			if (cur + v >= 100)
				continue;
			int vp = dir[cur + v];
			if (cnt[vp] >= 0)
				continue;
			cnt[vp] = cnt[cur] + 1;
			nxt.push(vp);
		}
	}

	cout << cnt[99];
}