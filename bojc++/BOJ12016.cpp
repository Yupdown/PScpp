#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

array<int64, 3> tasks[1 << 17];
int segment_tree[1 << 18];

int insert_segment(int* segment, int seg_index, int index, int x, int dx)
{
	if (!dx)
		return segment[seg_index] = 1;

	int l = seg_index * 2;
	int r = seg_index * 2 + 1;
	int v = 0;

	if (index < x + dx)
		v = insert_segment(segment, l, index, x, dx >> 1) + segment[r];
	else
		v = insert_segment(segment, r, index, x + dx, dx >> 1) + segment[l];

	return segment[seg_index] = v;
}

int find_segment(int* segment, int seg_index, int index, int x, int dx)
{
	if (!dx)
		return 0;

	int l = seg_index * 2;
	int r = seg_index * 2 + 1;

	if (index < x + dx)
		return find_segment(segment, l, index, x, dx >> 1);
	else
		return find_segment(segment, r, index, x + dx, dx >> 1) + segment[l];
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	int64 itg = 0LL;
	for (int i = 0; i < n; ++i)
	{
		tasks[i][0] = i;
		cin >> tasks[i][1];
		itg += tasks[i][1];
	}

	sort(tasks, tasks + n, [](const array<int64, 3>& lhs, const array<int64, 3>& rhs) -> bool {
		if (lhs[1] == rhs[1])
			return lhs[0] < rhs[0];
		return lhs[1] < rhs[1];
		});

	int64 last_task = 0LL;
	for (int i = n - 1; i >= 0; --i)
	{
		int64 k = n - i - 1;
		itg -= (last_task - tasks[i][1]) * k;
		last_task = tasks[i][1];

		tasks[i][2] = itg - k + find_segment(segment_tree, 1, (int)tasks[i][0], 0, 1 << 16);
		insert_segment(segment_tree, 1, (int)tasks[i][0], 0, 1 << 16);
	}

	sort(tasks, tasks + n, [](const array<int64, 3>& lhs, const array<int64, 3>& rhs) -> bool {
		return lhs[0] < rhs[0];
		});

	for (int i = 0; i < n; ++i)
		cout << tasks[i][2] << "\n";
}