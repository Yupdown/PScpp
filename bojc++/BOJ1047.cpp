#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

array<int, 3> table[40];

int get_cost(int x_0, int x_1, int y_0, int y_1)
{
	int dx = x_0 - x_1;
	int dy = y_0 - y_1;

	if (dx > 0 && dy > 0)
		return (dx + dy) * 2;
	return dx + dy;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i][0] >> table[i][1] >> table[i][2];

	int vmin = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = i; k < n; ++k)
			{
				for (int l = j; l < n; ++l)
				{
					int xmin = min(table[i][0], table[k][0]);
					int xmax = max(table[i][0], table[k][0]);
					int ymin = min(table[j][1], table[l][1]);
					int ymax = max(table[j][1], table[l][1]);

					int dx = xmax - xmin;
					int dy = ymax - ymin;
					int cost = dx + dy;
					if (dx > 0 && dy > 0)
						cost *= 2;

					priority_queue<int> pq;
					int cnt = 0;
					for (int m = 0; m < n; ++m)
					{
						if (table[m][0] < xmin || table[m][0] > xmax || table[m][1] < ymin || table[m][1] > ymax)
						{
							cost -= table[m][2];
							++cnt;
						}
						else
							pq.push(table[m][2]);
					}

					while (cost > 0 && !pq.empty())
					{
						cost -= pq.top();
						pq.pop();
						++cnt;
					}

					if (cost <= 0)
						vmin = min(vmin, cnt);
				}
			}
		}
	}

	cout << vmin;
}