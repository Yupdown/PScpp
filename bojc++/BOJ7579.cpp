#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int mi[100];
int ci[100];
int memo[1 << 14];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> mi[i];
	for (int i = 0; i < n; ++i)
		cin >> ci[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 10000; j >= ci[i]; --j)
		{
			if (memo[j - ci[i]] > 0)
				memo[j] = max(memo[j], memo[j - ci[i]] + mi[i]);
		}
		memo[ci[i]] = max(memo[ci[i]], mi[i]);
	}
	for (int i = 0; i <= 10000; ++i)
	{
		if (memo[i] >= m)
		{
			cout << i;
			return 0;
		}
	}
}