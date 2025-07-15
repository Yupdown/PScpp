#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[100];

int main()
{
	FASTIO();

	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	sort(table, table + n);

	int ret = 0;
	for (int x = 0; x < a; ++x)
	{
		int bx = b * x;
		int ap = a - x;

		for (int i = 0; i <= n; ++i)
		{
			int retp = 0;
			int p = 0;
			for (int j = 0; j < i; ++j)
			{
				if (table[j] >= p + a)
				{
					retp++;
					p += a;
				}
			}
			p += bx;
			for (int j = i; j < n; ++j)
			{
				if (table[j] >= p + ap)
				{
					retp++;
					p += ap;
				}
			}
			ret = max(ret, retp);
		}
	}
	cout << ret;
}