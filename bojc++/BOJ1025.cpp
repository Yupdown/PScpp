#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[10][10];
set<int> square;

int solution(int n, int m, int i, int j, int di, int dj, int v)
{
	if (i < 0 || i >= n || j < 0 || j >= m)
		return -1;
	int vp = v * 10 + table[i][j] - '0';
	return max(square.find(vp) != square.end() ? vp : -1, solution(n, m, i + di, j + dj, di, dj, vp));
}

int main()
{
	FASTIO();

	for (int i = 0; i * i < 1000000000; ++i)
		square.insert(i * i);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	int maxv = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int di = -n; di < n; ++di)
			{
				for (int dj = -m; dj < m; ++dj)
				{
					if (!di && !dj)
						continue;
					maxv = max(maxv, solution(n, m, i, j, di, dj, 0));
				}
			}
		}
	}
	cout << maxv;
}