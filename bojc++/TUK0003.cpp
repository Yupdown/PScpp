#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> table[100000];
int memo[1 << 20 + 1];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;

	sort(table, table + n);
	for (int m = 0, j = 0; m < 1 << 20; ++m)
	{
		while (m == table[j].first)
		{
			memo[m + table[j].second + 1] = max(memo[m + table[j].second + 1], memo[m] + 1);
			++j;
		}
		memo[m + 1] = max(memo[m + 1], memo[m]);
	}
	cout << memo[1 << 20];
}