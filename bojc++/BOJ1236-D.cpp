#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int n, m, a, d;
int s[1000];
int memo[1024][1024];

int func(int x)
{
	memset(memo, 0, sizeof(memo));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			if (i > 0)
			{
				memo[i][j] = memo[i - 1][j];
				if (i >= d && j > 0)
					memo[i][j] = max(memo[i][j], memo[i - d][j - 1] + a - s[i - d]);
			}
			memo[i][j] += s[i];
		}
	}

	int vmax = 0;
	for (int i = 0; i < x; ++i)
		vmax = max(vmax, (i + 1 < x) ? memo[n - 1][i] + a - s[n - 1] : memo[n - 1][i]);

	return vmax;
}

int main()
{
	FASTIO();

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	cin >> a >> d;

	int x = 1023;
	for (int dx = 512; dx > 0; dx >>= 1)
	{
		if (func(x - dx) >= m)
			x -= dx;
	}

	if (x == 1023)
		cout << -1;
	else
		cout << x - 1;
}