#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int node[100000];
int memo[100000];

int main()
{
	FASTIO();

	int t, n;
	cin >> t;

	while (t-- > 0)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> node[i];
		memset(memo, 0, sizeof(memo));
		for (int i = 0; i < n; ++i)
			++memo[node[i] - 1];
		for (int i = 0; i < n; ++i)
		{
			if (memo[i])
				continue;
			memo[i] = -1;
			int iter = node[i] - 1;
			while (!--memo[iter])
			{
				memo[iter] = -1;
				iter = node[iter] - 1;
			}
		}
		cout << accumulate(memo, memo + n, -n) / -2 << '\n';
	}
}