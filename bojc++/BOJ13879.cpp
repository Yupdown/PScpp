#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int solution(vector<map<int, int>>& memo, int m, int n, int d)
{
	if (n == 0)
		return 1;
	if (memo[n].count(d))
		return memo[n][d];
	int ret = 0;
	for (int i = 1; i <= d && i <= n; i *= m)
		ret += solution(memo, m, n - i, i);
	return memo[n][d] = ret;
}

int main()
{
	FASTIO();

	int p;
	cin >> p;
	while (p--)
	{
		int k, m, n, d = 1;
		cin >> k >> m >> n;
		vector<map<int, int>> memo(n + 1);
		cout << k << " " << solution(memo, m, n, n) << "\n";
	}
}