#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[10000];
int memo[10001];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	for (int i = 0; i < n; ++i)
	{
		memo[i + 1] = max(memo[i + 1], memo[i]);
		for (int j = 0, s = 0; j < m;)
		{
			s += table[i + j];
			if (i + ++j * 2 > n)
				break;
			memo[i + j * 2] = max(memo[i + j * 2], memo[i] + s);
		}
	}

	cout << memo[n];
}