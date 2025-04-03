#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

constexpr int64 MOD = 1000000007;
constexpr int SEGBASE = 1 << 17;
int64 table[SEGBASE << 1];
pair<int64, int64> task[SEGBASE << 1];

void update_segment_table(int l, int r)
{
	if (!l && !r)
		return;
	if (l < SEGBASE)
		table[l] = table[l << 1] + table[l << 1 | 1];
	if (r < SEGBASE)
		table[r] = table[r << 1] + table[r << 1 | 1];
	update_segment_table(l >> 1, r >> 1);
}

void update_segment_task(int l, int r, int a, int64 b)
{
	if (l || r)
		update_segment_task(l >> 1, r >> 1, a, b);
}

int64 get_segment(int l, int r)
{
	return 0;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[SEGBASE + i];
	for (int i = SEGBASE - 1; i >= 0; --i)
		table[i] = table[i << 1] + table[i << 1 | 1];
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int c, x, y;
		cin >> c >> x >> y;
		if (c < 4)
		{
			int64 v;
			cin >> v;
			update_segment_task(SEGBASE + x - 1, SEGBASE + y - 1, c, v);
			update_segment_table(SEGBASE + x - 1, SEGBASE + y - 1);
		}
		else
			cout << get_segment(SEGBASE + x - 1, SEGBASE + y - 1) << "\n";
	}
}