#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int seed[2000][2000];
vector<pair<pair<int, int>, bool>> line;

int main()
{
	FASTIO();

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n * m; ++i)
		cin >> seed[i / m][i % m];

	for (int i = 0; i < n * m; ++i)
	{
		int x = i % m;
		int y = i / m;

		if (!seed[y][x])
			continue;

		if (!(k > 1))
			line.push_back(make_pair(make_pair(x, y), true));
		else
		{
			if (x + k <= m && seed[y][x + 1] && seed[y][x + k - 1])
				line.push_back(make_pair(make_pair(x, y), true));
			if (y + k <= n && seed[y + 1][x] && seed[y + k - 1][x])
				line.push_back(make_pair(make_pair(x, y), false));
		}
	}
	pair<pair<int, int>, bool> line_rep[2] = { line.front(), line.back() };

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < k; ++j)
			seed[line_rep[i].first.second + (j * !line_rep[i].second)][line_rep[i].first.first + (j * line_rep[i].second)] -= 1;
	}

	vector<pair<int, int>> output;

	for (int i = 0; i < n * m; ++i)
	{
		int x = i % m;
		int y = i / m;

		if (seed[y][x] < 0)
			output.push_back(make_pair(y + 1, x + 1));
	}

	cout << output.size() << '\n';
	for (pair<int, int> iter : output)
		cout << iter.first << ' ' << iter.second << '\n';

	return 0;
}