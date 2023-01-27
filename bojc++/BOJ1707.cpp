#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edge[20000];
int temp[20000];

int Function(int index, bool flipflop)
{
	temp[index] = flipflop + 1;

	for (int next : edge[index])
	{
		if (temp[next] == temp[index] || (!temp[next] && !Function(next, !flipflop)))
			return 0;
	}

	return 1;
}

int main()
{
	FASTIO();

	int k;
	cin >> k;

	while (k-- > 0)
	{
		int v, e;
		cin >> v >> e;

		for (int i = 0; i < v; ++i)
		{
			edge[i].clear();
			temp[i] = 0;
		}

		for (int i = 0; i < e; ++i)
		{
			int lhs, rhs;
			cin >> lhs >> rhs;
			edge[lhs - 1].push_back(rhs - 1);
			edge[rhs - 1].push_back(lhs - 1);
		}

		bool r = true;
		for (int i = 0; i < v && r; ++i)
		{
			if (!temp[i])
				r &= Function(i, 0);
		}

		cout << (r ? "YES" : "NO") << "\n";
	}
}