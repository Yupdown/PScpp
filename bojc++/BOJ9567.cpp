#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[3000000];

int insert(int n, int i)
{
	return table[i] = table[i] < 0 ? (i + 1) % n : insert(n, table[i]);
}

int main()
{
	FASTIO();
	memset(table, -1, sizeof(table));

	int n, k;
	cin >> n >> k;
	while (k--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		for (int i = 1; i <= y; ++i)
		{
			for (int j = 0; j < x; ++j)
				insert(n, (static_cast<long long>(a) * i + b) % n);
		}
	}
	int r = 0;
	while (table[r] >= 0)
		r = table[r];
	cout << r;
}