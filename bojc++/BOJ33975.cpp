#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

ll memo[2][100001];

int main()
{
	FASTIO();

	int n;
	string c1, c2;
	cin >> n >> c1 >> c2;

	ll xa = 0, xb = 0;
	for (int i = 0; i < n * 2; ++i)
	{
		if (c1[i] == 'R')
		{
			xa++;
			memo[0][xa] = memo[0][xa - 1];
		}
		else
			memo[0][xa]++;
		if (c2[i] == 'R')
		{
			xb++;
			memo[1][xb] = memo[1][xb - 1];
		}
		else
			memo[1][xb]++;
	}

	ll retA = memo[1][0] + 1;
	ll retB = memo[0][0] + 1;
	for (int i = 1; i <= n; ++i)
	{
		retA += max(memo[1][i] - memo[0][i - 1] + 1, 0ll);
		retB += max(memo[0][i] - memo[1][i - 1] + 1, 0ll);
	}
	cout << min(retA, retB) - 2;
}