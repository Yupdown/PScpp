#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long h[1 << 18];
long long hl[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, m, l;
		cin >> n >> m >> l;

		memset(h, 0, sizeof(h));
		memset(hl, 0, sizeof(hl));

		for (int i = 0; i < n; ++i)
		{
			int l, r;
			cin >> l >> r;
			h[i + 1] = r;
			hl[i] = r - l + 2;
		}

		vector<vector<long long>> vv;
		priority_queue<long long> pq;
		vv.resize(n + 1);
		for (int i = 0; i < m; ++i)
		{
			int x, v;
			cin >> x >> v;

			int p = prev(lower_bound(h, h + n + 1, x)) - h;
			vv[p].push_back(v);
		}

		long long r = 0;
		long long k = 1;
		for (int i = 0; i < n; ++i)
		{
			for (auto v : vv[i])
				pq.push(v);
			long long itv = hl[i];
			while (!pq.empty() && k < itv)
			{
				k += pq.top();
				pq.pop();
				++r;
			}
			if (k < itv)
			{
				r = -1;
				break;
			}
		}

		cout << r << '\n';
	}
}