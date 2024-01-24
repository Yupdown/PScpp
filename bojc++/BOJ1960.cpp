#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> r[500];
pair<int, int> c[500];
char output[500][501];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		r[i].second = c[i].second = i;
	for (int i = 0; i < n; ++i)
		cin >> r[i].first;
	for (int i = 0; i < n; ++i)
		cin >> c[i].first;

	sort(r, r + n, greater<pair<int, int>>());
	for (int i = 0; i < n; ++i)
	{
		sort(c, c + n, greater<pair<int, int>>());
		for (int j = 0; j < n; ++j)
		{
			if (r[i].first && c[j].first)
			{
				r[i].first--;
				c[j].first--;
				output[r[i].second][c[j].second] = '1';
			}
			else
				output[r[i].second][c[j].second] = '0';
		}
	}

	bool flag = true;
	for (int i = 0; i < n; ++i)
		flag &= !r[i].first && !c[i].first;

	if (flag)
	{
		cout << 1 << '\n';
		for (int i = 0; i < n; ++i)
			cout << output[i] << '\n';
	}
	else
		cout << -1;
}