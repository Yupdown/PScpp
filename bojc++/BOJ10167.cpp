#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

tuple<int, int, int64> table[3000];

// each element respectifully:
// 0: sum of the segment
// 1: max segment value within the segment
// 2: max segment value within the segment, including the first element of the segment
// 3: max segment value within the segment, including the last element of the segment
constexpr int SEGBASE = 1 << 12;
int64 memo[SEGBASE << 1][4];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	map<int, int> ymap;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		int64 w;
		cin >> x >> y >> w;
		table[i] = make_tuple(x, y, w);
		ymap.emplace(y, 0);
	}
	int c = 0;
	for (auto& [k, v] : ymap)
		v = c++;
	sort(table, table + n);

	int64 vmax = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i > 0 && get<0>(table[i - 1]) == get<0>(table[i]))
			continue;
		memset(memo, 0, sizeof(memo));
		for (int j = i; j < n; ++j)
		{
			const auto& [x, y, w] = table[j];
			int p = SEGBASE + ymap[y];
			for (int k = 0; k < 4; ++k)
				memo[p][k] += w;
			while (p >>= 1)
			{
				auto m = memo[p];
				auto lm = memo[p << 1];
				auto rm = memo[p << 1 | 1];

				m[0] = lm[0] + rm[0];
				m[1] = max(max(lm[1], rm[1]), lm[3] + rm[2]);
				m[2] = max(lm[2], lm[0] + rm[2]);
				m[3] = max(rm[3], lm[3] + rm[0]);
			}
			if (j + 1 < n && get<0>(table[j]) == get<0>(table[j + 1]))
				continue;
			vmax = max(vmax, memo[1][1]);
		}
	}

	cout << vmax;
}