#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

int tree[1000000];

int64 Function(int n, int h)
{
	int64 r = 0;
	for (int i = 0; i < n; ++i)
		r += max<int64>(0, tree[i] - h);
	return r;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	int vmax = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> tree[i];
		vmax = max(vmax, tree[i]);
	}

	int from = 0, to = vmax;
	while (from + 1 < to)
	{
		int mid = (from + to) / 2;

		if (Function(n, mid) >= m)
			from = mid;
		else
			to = mid;
	}

	cout << from << endl;
}