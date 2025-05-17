#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

int table[2000][2000];
pair<int, int> query[2000];
pair<int, int> memo[2000];
constexpr ll MOD = 998'244'353;

int main()
{
	FASTIO();

	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n * n; ++i)
		cin >> table[i / n][i % n];
	for (int i = 0; i < q; ++i)
		cin >> query[i].first >> query[i].second;
	
	vector<int> temp(n);

	int v = -1;
	for (int i = 0; i < q; ++i)
	{
		if (query[i].first == 1)
			v = i;
	}

	if (v < 0)
		cout << 1;
	else
	{
		for (int i = q - 1; i >= v; --i)
		{
			for (int j = 0; j < n; ++j)
				memo[j] = make_pair(table[j][query[i].second - 1], temp[j]);
			sort(memo, memo + n);
			temp[0] = 0;
			for (int j = 1; j < n; ++j)
				temp[j] = temp[j - 1] + (memo[j - 1] != memo[j]);
		}
		for (int j = 0; j < n; ++j)
			memo[j] = make_pair(table[j][query[v].second - 1], temp[j]);
		sort(memo, memo + n);
		temp[0] = 0;
		for (int j = 1; j < n; ++j)
			temp[j] = temp[j - 1] + (memo[j - 1] != memo[j]);

		ll ret = 1, addv = 1;
		for (int i = 1, c = 1; i < n; ++i)
		{
			if (temp[i - 1] == temp[i])
				addv = (addv * ++c) % MOD;
			else
			{
				ret = (ret * addv) % MOD;
				addv = 1;
				c = 1;
			}
		}
		ret = (ret * addv) % MOD;
		cout << ret;
	}
}