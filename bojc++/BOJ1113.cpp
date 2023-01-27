#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char height_map[64][64];
char flood_map[64][64];

int SearchChunk(int n, int m, int h, int r, int c)
{
	int cnt = 0;
	queue<pair<int, int>> next_nodes;
	queue<pair<int, int>> flood_back;
	next_nodes.push(make_pair(r, c));

	while (!next_nodes.empty())
	{
		r = next_nodes.front().first;
		c = next_nodes.front().second;
		next_nodes.pop();

		if (height_map[r][c] - 48 >= h)
			continue;
		if (flood_map[r][c] > 0)
			continue;
		if (r <= 0 || r + 1 >= n || c <= 0 || c + 1 >= m || flood_map[r][c] < 0)
		{
			while (!flood_back.empty())
			{
				r = flood_back.front().first;
				c = flood_back.front().second;
				flood_back.pop();
				flood_map[r][c] = -1;
			}
			return 0;
		}

		next_nodes.push(make_pair(r + 1, c));
		next_nodes.push(make_pair(r - 1, c));
		next_nodes.push(make_pair(r, c + 1));
		next_nodes.push(make_pair(r, c - 1));

		++cnt;
		flood_map[r][c] = 1;
		flood_back.push(make_pair(r, c));
	}

	return cnt;
}

int SearchFloor(int n, int m, int h)
{
	memset(flood_map, 0, sizeof(flood_map));

	int r = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		for (int j = 1; j < m - 1; ++j)
			r += SearchChunk(n, m, h, i, j);
	}

	return r;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> height_map[i];

	int r = 0;
	for (int h = 2; h < 10; ++h)
		r += SearchFloor(n, m, h);

	cout << r << endl;
}