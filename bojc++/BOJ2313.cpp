#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
pair<int, int> ret[1000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	long long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		int l;
		cin >> l;

		long long psum = 0;
		long long pmax = LLONG_MIN;
		pair<long long, int> smin = { LLONG_MAX, 0 };

		for (int j = 0; j < l; ++j)
		{
			long long v;
			cin >> v;

			if (psum <= smin.first)
				smin = { psum, j };
			psum += v;
			if (pmax < psum - smin.first)
			{
				pmax = psum - smin.first;
				ret[i] = { smin.second, j };
			}
			else if (pmax == psum - smin.first && j - smin.second < ret[i].second - ret[i].first)
				ret[i] = { smin.second, j };
		}
		sum += pmax;
	}
	cout << sum << '\n';
	for (int i = 0; i < n; ++i)
		cout << ret[i].first + 1 << ' ' << ret[i].second + 1 << '\n';
}