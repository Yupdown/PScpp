#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, s;
		cin >> n >> s;
		pair<int, int> xminmax = make_pair(s, s);
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			xminmax.first = min(xminmax.first, x);
			xminmax.second = max(xminmax.second, x);
		}
		cout << xminmax.second - xminmax.first + min(xminmax.second - s, s - xminmax.first) << "\n";
	}
}