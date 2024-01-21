#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[2][1000];
map<int, int> cnt;

int main()
{
	FASTIO();

	int t, n, m;
	cin >> t >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[0][i];
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> table[1][i];

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = i; j < n; ++j)
		{
			sum += table[0][j];
			if (cnt.find(sum) == cnt.end())
				cnt[sum] = 0;
			cnt[sum] += 1;
		}
	}

	long long ret = 0;
	for (int i = 0; i < m; ++i)
	{
		int sum = 0;
		for (int j = i; j < m; ++j)
		{
			sum += table[1][j];
			if (cnt.find(t - sum) != cnt.end())
				ret += cnt[t - sum];
		}
	}

	cout << ret;
}