#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
pair<long long, long long> table[200000];

int main()
{
	FASTIO();

	long long n, h;
	cin >> n >> h;
	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;
	sort(table, table + n);
	vector<long long> segs;
	long long lp = 0;
	for (int i = 0; i < n; ++i)
	{
		long long delta = table[i].first - lp - 1;
		if (delta > 0)
			segs.push_back(delta);
		lp = max(lp, table[i].second);
	}
	segs.push_back(h - lp);
	sort(segs.begin(), segs.end(), std::greater<long long>());
	vector<long long> psum = segs;
	for (int i = 1; i < psum.size(); ++i)
		psum[i] += psum[i - 1];
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		long long t;
		cin >> t;
		if (segs.front() <= t - 1)
		{
			cout << 0 << "\n";
		}
		else
		{
			auto it = prev(lower_bound(segs.begin(), segs.end(), t - 1, std::greater<long long>()));
			long long index = distance(segs.begin(), it);
			long long sum = psum[index] - ((t - 1) * (index + 1));
			cout << sum << "\n";
		}
	}
}