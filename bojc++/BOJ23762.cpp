#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
constexpr int INF = 0x7FFFFFFF;
pair<int, int> table[100000];
vector<int> memo[100000][3];

vector<int> solution(int n, int i, int c)
{
	if (i == n)
		return vector<int>(1, 0);
	if (c < 0)
		return vector<int>(1, INF);
	if (memo[i][c][0] < INF)
		return memo[i][c];
	auto ret = solution(n, i + 1, c - 1);
	ret.push_back(table[i].second);
	if (i + 3 < n)
	{
		auto v = solution(n, i + 4, c);
		v[0] += table[i + 3].first - table[i].first;
		ret = min(ret, v);
	}
	return memo[i][c] = ret;
}

int main()
{
	FASTIO();
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> table[i].first;
		table[i].second = i;
		for (int j = 0; j <= n % 4; ++j)
			memo[i][j] = vector<int>(1, INF);
	}
	sort(table, table + n);
	auto ret = solution(n, 0, n % 4);
	for (int v : ret)
		cout << v << "\n";
}