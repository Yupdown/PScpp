#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
constexpr int INF = 100000000;
int table[301];
int memo[301][301][2];

int solution(int n, int from, int to, int right, int k)
{
	if (k == 0)
		return 0;
	if (memo[from][to][right] >= 0)
		return memo[from][to][right];
	int ret = INF;
	if (from > 0)
		ret = min(ret, solution(n, from - 1, to, 0, k - 1) + k * (right ? table[to] - table[from - 1] : table[from] - table[from - 1]));
	if (to + 1 < n)
		ret = min(ret, solution(n, from, to + 1, 1, k - 1) + k * (right ? table[to + 1] - table[to] : table[to + 1] - table[from]));
	return memo[from][to][right] = ret;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> table[i];
	sort(table, table + n + 1);

	int ret = 0;
	int zero = distance(table, lower_bound(table, table + n + 1, 0));
	for (int k = 1; k <= n; ++k)
	{
		memset(memo, -1, sizeof(memo));
		ret = max(ret, k * m - solution(n + 1, zero, zero, 1, k));
	}
	cout << ret;
}