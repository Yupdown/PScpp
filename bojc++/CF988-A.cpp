#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[512];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		memset(memo, 0, sizeof(memo));
		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			memo[v]++;
		}

		int ret = 0;
		for (int i = 0; i <= n; ++i)
			ret += memo[i] / 2;
		cout << ret << '\n';
	}
}