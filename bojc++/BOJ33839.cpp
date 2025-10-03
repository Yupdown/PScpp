#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];
pair<long long, long long> delta[200000];

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	for (int i = 1; i < n; ++i)
		delta[i].first = delta[i - 1].first - table[i - 1] * 2;
	for (int i = n - 2; i >= 0; --i)
		delta[i].second = delta[i + 1].second - table[i + 1] * 2;
	priority_queue<pair<long long, int>> pq;
	long long delta_max = LLONG_MIN;
	pair<int, int> ret;
	pq.emplace(delta[n - 1].second, 1 - n);
	for (int lhs = n - 1; lhs >= 0; --lhs)
	{
		if (lhs > 0)
			pq.emplace(delta[lhs - 1].second, 1 - lhs);
		while (!pq.empty() && -pq.top().second - lhs > k)
			pq.pop();
		pq.emplace(delta[lhs].second, -lhs);
		auto [rhs_delta, rhs] = pq.top();
		rhs = -rhs;
		long long delta_cur = delta[lhs].first + rhs_delta;
		if (delta_cur >= delta_max)
		{
			delta_max = delta_cur;
			ret = make_pair(lhs, rhs);
		}
	}
	long long vsum = accumulate(table, table + n, 0);
	cout << vsum + delta_max << "\n";
	cout << ret.first + 1 << " " << ret.second + 1;
}