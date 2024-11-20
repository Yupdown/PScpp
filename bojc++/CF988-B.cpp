#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long table[200001];

pair<long long, long long> solution(long long k)
{
	long long v = k - 2;
	for (int i = 1; i <= 200000; ++i)
	{
		if (table[i] == 0)
			continue;
		if (v % i)
			continue;
		long long t = v / i;
		bool flag = table[t] > 0;
		if (t == i)
			flag = table[t] > 1;
		if (flag)
			return { i, t };
	}
	return { 0, 0 };
}

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long k;
		cin >> k;
		memset(table, 0, sizeof(table));
		for (int i = 0; i < k; ++i)
		{
			int v;
			cin >> v;
			table[v]++;
		}
		auto [i, j] = solution(k);
		cout << i << ' ' << j << '\n';
	}
}