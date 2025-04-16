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

void apply_segment_task(int i, int lv)
{
	table[i] = (table[i] * task[i].first + task[i].second * (1ll << lv)) % MOD;
	if (i < SEGBASE)
	{
		task[i << 1] = merge_segment_task(task[i << 1], task[i]);
		task[i << 1 | 1] = merge_segment_task(task[i << 1 | 1], task[i]);
	}
	task[i] = make_pair(1, 0);
}

void add_segment(int l, int r, const pair<int64, int64>& src, int lv)
{
	int lp = l >> lv;
	int rp = r >> lv;

	if (rp - lp > 1)
	{
		if (~lp & 1)
			task[lp + 1] = merge_segment_task(task[lp + 1], src);
		if (rp & 1)
			task[rp - 1] = merge_segment_task(task[rp - 1], src);
	}

	apply_segment_task(lp, lv);
	apply_segment_task(lp ^ 1, lv);
	apply_segment_task(rp, lv);
	apply_segment_task(rp ^ 1, lv);

	if (lv > 0)
	{
		add_segment(l, r, src, lv - 1);
		table[lp] = (table[lp << 1] + table[lp << 1 | 1]) % MOD;
		table[rp] = (table[rp << 1] + table[rp << 1 | 1]) % MOD;
	}
	else
	{
		task[lp] = merge_segment_task(task[lp], src);
		apply_segment_task(lp, lv);
		if (lp < rp)
		{
			task[rp] = merge_segment_task(task[rp], src);
			apply_segment_task(rp, lv);
		}
	}
}

int64 get_segment(int l, int r)
{
	int64 ret = 0;
	if (l & 1)
		ret += table[l++];
	if (~r & 1)
		ret += table[r--];
	if (l < r)
		ret += get_segment(l >> 1, r >> 1);
	return ret % MOD;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[SEGBASE + i];
	for (int i = SEGBASE - 1; i > 0; --i)
		table[i] = (table[i << 1] + table[i << 1 | 1]) % MOD;
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
			add_segment(l, r, src, 17);
		}
		else
		{
			add_segment(l, r, make_pair(1, 0), 17);
			cout << get_segment(l, r) << "\n";
		}
	}
}