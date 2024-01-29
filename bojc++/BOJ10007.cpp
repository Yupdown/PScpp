#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;
using vec64 = struct { int64 x, y; };
using line64 = pair<vec64, vec64>;

inline int64 orientation(int64 ax, int64 ay, int64 bx, int64 by, int64 cx, int64 cy)
{
	return (by - ay) * (cx - bx) - (bx - ax) * (cy - by);
}

inline bool compare_ccw(const vec64& lhs, const vec64& rhs)
{
	return orientation(0, 0, lhs.x, lhs.y, rhs.x, rhs.y) < 0;
}

inline int64 to_hash(const vec64& v)
{
	return v.x | v.y << 32;
}

line64 lines[500000];
pair<int, int> li[500000];
vector<vec64> v;
unordered_map<int64, int> vtoi;
priority_queue<int> pq;
pair<int, int> table[1000000];
int memo[1000002][101];

int main()
{
	FASTIO();

	int k, n;
	cin >> k >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> lines[i].first.x >> lines[i].first.y >> lines[i].second.x >> lines[i].second.y;
		v.push_back(lines[i].first);
		v.push_back(lines[i].second);
	}

	sort(v.begin(), v.end(), compare_ccw);
	reverse(v.begin(), v.end());
	vtoi[to_hash(v[0])] = 0;
	int j = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (orientation(0, 0, v[i - 1].x, v[i - 1].y, v[i].x, v[i].y) != 0)
			j++;
		vtoi[to_hash(v[i])] = j;
	}

	for (int i = 0; i < n; ++i)
	{
		li[i].first = vtoi[to_hash(lines[i].first)];
		li[i].second = vtoi[to_hash(lines[i].second)];
		if (li[i].first > li[i].second)
			swap(li[i].first, li[i].second);
	}
	sort(li, li + n);

	int cnt = 0;
	int rmax = 0;
	for (int i = 0, l = 0; i <= j; ++i)
	{
		while (l < n && li[l].first <= i)
		{
			rmax = max(rmax, li[l].second);
			pq.push(-li[l].second);
			++l, ++cnt;
		}
		table[i].first = cnt;
		table[i].second = rmax;

		while (!pq.empty() && -pq.top() <= i)
		{
			pq.pop();
			--cnt;
		}
	}

	for (int i = 0; i <= j + 1; ++i)
	{
		for (int l = 1; l <= k; ++l)
		{
			if (i > 0)
				memo[i][l] = max(memo[i][l], memo[i - 1][l]);
			memo[table[i].second + 1][l] = max(memo[table[i].second + 1][l], memo[i][l - 1] + table[i].first);
		}
	}

	int ret = 0;
	for (int i = 0; i <= k; ++i)
		ret = max(ret, memo[j + 1][i]);

	cout << ret;
}