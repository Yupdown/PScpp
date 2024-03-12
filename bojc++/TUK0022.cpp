#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	memset(table, -1, sizeof(table));
	int ret = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (table[a - 1] >= 0)
		{
			ret = -2;
			break;
		}

		table[a - 1] = b - 1;

		int ti = b - 1;
		while (table[ti] >= 0 && table[ti] != a - 1)
			ti = table[ti];

		if (table[ti] < 0)
			ret = ti;
		else
		{
			ret = -2;
			break;
		}
	}

	cout << ret + 1;
}