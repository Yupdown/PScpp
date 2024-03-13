#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<pair<int, int>> hxy;
vector<pair<int, int>> cxy;

int func(int m, int i, int mask)
{
	if (m > 0)
	{
		int v = numeric_limits<int>::max();
		for (int j = i; j < cxy.size(); ++j)
			v = min(v, func(m - 1, j + 1, mask | 1 << j));
		return v;
	}

	int v = 0;
	for (int j = 0; j < hxy.size(); ++j)
	{
		int t = numeric_limits<int>::max();
		for (int k = 0; k < cxy.size(); ++k)
		{
			if (~(mask >> k) & 1)
				continue;
			t = min(t, abs(hxy[j].first - cxy[k].first) + abs(hxy[j].second - cxy[k].second));
		}
		v += t;
	}

	return v;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int v;
			cin >> v;
			switch (v)
			{
			case 1:
				hxy.push_back(make_pair(i, j));
				break;
			case 2:
				cxy.push_back(make_pair(i, j));
				break;
			}
		}
	}

	cout << func(m, 0, 0);
}