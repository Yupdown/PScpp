#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	bool flags[10]{};
	for (int i = 0; i < m; ++i)
	{
		int v;
		cin >> v;
		flags[v] = true;
	}

	int dmin = abs(n - 100);
	if (!flags[0])
		dmin = min(dmin, n + 1);
	for (int i = 1; i < max(n * 2, 100); ++i)
	{
		int d = 0;
		for (int ip = i; ip > 0; ip /= 10, ++d)
		{
			if (flags[ip % 10])
				goto escape;
		}
		dmin = min(dmin, abs(n - i) + d);
	escape:;
	}

	cout << dmin;
}