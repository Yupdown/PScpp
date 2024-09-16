#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
pair<int, int> table[1000000];
int memo[1 << 21];
constexpr int BASE = 1 << 20;

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i].second >> table[i].first;
	sort(table, table + n);
	memset(memo, -1, sizeof(memo));
	int sum = BASE;
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		if (memo[sum] < 0)
			memo[sum] = table[i].first;
		sum += table[i].second * 2 - 1;
		if (memo[sum] >= 0)
			ret = max(ret, table[i].first - memo[sum]);
	}
	cout << ret;
}