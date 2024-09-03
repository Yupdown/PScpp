#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1 << 18];
int memo[18];

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 1 << n; ++i)
		cin >> table[i];
	sort(table, table + (1 << n), greater<int>());
	int ret = 0;
	for (int i = 0; i < 1 << n; ++i)
	{
		for (int j = n - 1; 1 << j > i; --j)
		{
			if (table[i] - table[(1 << j) + memo[j]] <= k)
				++memo[j], ++ret;
		}
	}
	cout << ret;
}