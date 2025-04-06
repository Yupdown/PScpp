#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

constexpr int64 MOD = 1000000007;
constexpr int64 SEGBASE = 1 << 17;
int64 table[SEGBASE << 1];
pair<int64, int64> task[SEGBASE << 1];

pair<int64, int64> merge_segment_task(const pair<int64, int64>& lhs, const pair<int64, int64>& rhs)
{
	return make_pair((lhs.first * rhs.first) % MOD, (rhs.first * lhs.second + rhs.second) % MOD);
}

bool is_segment_applied(int i)
{
	return task[i] == make_pair(1, 0);
}

void apply_segment_task(int i, int64 n)
{
	table[i] = (table[i] * task[i].first + task[i].second * n) % MOD;
	if (i < SEGBASE)
	{
		task[i << 1] = merge_segment_task(task[i << 1], task[i]);
		task[i << 1 | 1] = merge_segment_task(task[i << 1 | 1], task[i]);
	}
	task[i] = make_pair(1, 0);
}

void update_segment_table(int l, int r)
{
	if (!l && !r)
		return;
	if (l < SEGBASE)
		table[l] = (table[l << 1] + table[l << 1 | 1]) % MOD;
	if (r < SEGBASE)
		table[r] = (table[r << 1] + table[r << 1 | 1]) % MOD;
	update_segment_table(l >> 1, r >> 1);
}

void update_segment_task(int l, int r, int64 n)
{
	if (l || r)
		update_segment_task(l >> 1, r >> 1, n << 1);
	apply_segment_task(l, n);
	apply_segment_task(l & ~1, n);
	apply_segment_task(r, n);
	apply_segment_task(r | 1, n);
}

void add_segment_task(int l, int r, const pair<int64, int64>& src, int64 n)
{
	if (l < r)
		add_segment_task((l + 1) >> 1, (r - 1) >> 1, src, n << 1);
	if (l & 1)
	{
		task[l] = merge_segment_task(task[l], src);
		apply_segment_task(l, n);
		apply_segment_task(l & ~1, n);
		if (l < SEGBASE)
		{
			apply_segment_task(l << 1, n >> 1);
			apply_segment_task(l << 1 | 1, n >> 1);
		}
	}
	if (~r & 1)
	{
		task[r] = merge_segment_task(task[r], src);
		apply_segment_task(r, n);
		apply_segment_task(r | 1, n);
		if (r < SEGBASE)
		{
			apply_segment_task(r << 1, n >> 1);
			apply_segment_task(r << 1 | 1, n >> 1);
		}
	}
}

int64 get_segment(int l, int r)
{
	int64 ret = l < r ? get_segment((l + 1) >> 1, (r - 1) >> 1) : 0;
	if (l & 1)
		ret += table[l];
	if (~r & 1)
		ret += table[r];
	return ret % MOD;
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
	fill(begin(task), end(task), make_pair(1, 0));
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int c, x, y;
		cin >> c >> x >> y;
		int l = SEGBASE + x - 1;
		int r = SEGBASE + y - 1;
		if (c < 4)
		{
			int64 v;
			cin >> v;
			pair<int64, int64> src;
			switch (c)
			{
			case 1:
				src = make_pair(1, v);
				break;
			case 2:
				src = make_pair(v, 0);
				break;
			case 3:
				src = make_pair(0, v);
				break;
			}
			update_segment_task(l, r, 1);
			add_segment_task(l, r, src, 1);
			update_segment_table(l, r);
		}
		else
		{

			update_segment_task(l, r, 1);
			update_segment_table(l, r);
			cout << get_segment(l, r) << "\n";
		}
	}
}