#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char table[1500][1501];
int level[1500][1500];
int flood[1500][1500];
vector<pair<int, int>> lpos;
queue<pair<int, int>> bps[3000];

int solution(int r, int c, int d)
{
	while (!bps[d].empty())
	{
		auto [i, j] = bps[d].front();
		bps[d].pop();

		if (i == lpos[1].first && j == lpos[1].second)
			return d;

		for (int k = 0; k < 4; ++k)
		{
			int ip = i + "0211"[k] - '1';
			int jp = j + "1102"[k] - '1';

			if (ip < 0 || ip >= r)
				continue;
			if (jp < 0 || jp >= c)
				continue;
			if (flood[ip][jp])
				continue;

			flood[ip][jp] = 1;
			bps[max(d, level[ip][jp])].push(make_pair(ip, jp));
		}
	}

	return solution(r, c, d + 1);
}

int main()
{
	FASTIO();

	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		cin >> table[i];

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			level[i][j] = table[i][j] == 'X' ? 1 << 16 : 0;
			if (table[i][j] == 'L')
				lpos.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i > 0)
				level[i][j] = min(level[i][j], level[i - 1][j] + 1);
			if (j > 0)
				level[i][j] = min(level[i][j], level[i][j - 1] + 1);
		}
	}

	for (int i = r - 1; i >= 0; --i)
	{
		for (int j = c - 1; j >= 0; --j)
		{
			if (i < r - 1)
				level[i][j] = min(level[i][j], level[i + 1][j] + 1);
			if (j < c - 1)
				level[i][j] = min(level[i][j], level[i][j + 1] + 1);
		}
	}

	bps[0].push(lpos[0]);
	cout << solution(r, c, 0);
}