#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[128][128];
pair<int, int> query[1000];

int main()
{
	FASTIO();

	int n, r;
	cin >> n >> r;

	for (int i = 0; i < 1 << n; ++i)
	{
		for (int j = 0; j < 1 << n; ++j)
			cin >> table[i][j];
	}
	for (int i = 0; i < r; ++i)
		cin >> query[i].first >> query[i].second;
	for (int i = 0; i < 1 << n; ++i)
	{
		for (int j = 0; j < 1 << n; ++j)
		{
			int ip = i;
			int jp = j;

			for (int k = r - 1; k >= 0; --k)
			{
				int l = 1 << query[k].second;
				int m = 1 << n - query[k].second;
				int pai = ip % l;
				int paj = jp % l;
				int pbi = ip / l;
				int pbj = jp / l;
				switch (query[k].first)
				{
				case 1:
					pai = l - ip % l - 1;
					break;
				case 2:
					paj = l - jp % l - 1;
					break;
				case 3:
					pai = l - jp % l - 1;
					paj = ip % l;
					break;
				case 4:
					pai = jp % l;
					paj = l - ip % l - 1;
					break;
				case 5:
					pbi = m - ip / l - 1;
					break;
				case 6:
					pbj = m - jp / l - 1;
					break;
				case 7:
					pbi = m - jp / l - 1;
					pbj = ip / l;
					break;
				case 8:
					pbi = jp / l;
					pbj = m - ip / l - 1;
					break;
				}
				ip = pbi * l + pai;
				jp = pbj * l + paj;
			}

			cout << table[ip][jp] << " ";
		}
		cout << "\n";
	}
}