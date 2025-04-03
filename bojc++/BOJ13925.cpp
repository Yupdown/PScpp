#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

constexpr int SEGBASE = 1 << 17;
int64 table[SEGBASE << 1];
vector<pair<int, int64>> tasks[SEGBASE << 1];

void update_segment(int l, int r, int a, int64 b)
{

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
			update_segment(SEGBASE + x - 1, SEGBASE + y - 1, c, v);
		}
		else
			cout << get_segment(SEGBASE + x - 1, SEGBASE + y - 1) << "\n";
	}
}