#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> hpts[200000];
vector<int> vpts[200000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		x += 100000;
		y += 100000;
		hpts[y].push_back(x);
		vpts[x].push_back(y);
	}

	for (int i = 0; i < 200000; ++i)
	{
		sort(hpts[i].begin(), hpts[i].end());
		sort(vpts[i].begin(), vpts[i].end());
	}

	string s;
	cin >> s;
	int x = 100000;
	int y = 100000;
	for (int i = 0; i < m; ++i)
	{
		char c = s[i];
		int o = c == 'R' || c == 'U' ? 1 : -1;
		switch (c)
		{
		case 'L':
		case 'R':
			x = *(lower_bound(hpts[y].begin(), hpts[y].end(), x) + o);
			break;
		case 'U':
		case 'D':
			y = *(lower_bound(vpts[x].begin(), vpts[x].end(), y) + o);
			break;
		}
	}
	cout << x - 100000 << " " << y - 100000;
}