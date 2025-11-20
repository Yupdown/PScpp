#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table_a[200000];
int table_b[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table_a[i];
		for (int i = 0; i < n; ++i)
			cin >> table_b[i];
		int flag = 0;
		for (int s = 20; s >= 0 && flag == 0; --s)
		{
			int diffcnt = 0;
			int lastdiff = -1;
			for (int i = 0; i < n; ++i)
			{
				int mask = 1 << s;
				if ((table_a[i] & mask) != (table_b[i] & mask))
				{
					diffcnt++;
					lastdiff = i;
				}
			}
			if (diffcnt % 2)
			{
				if (lastdiff % 2)
					flag = 1;
				else
					flag = -1;
			}
		}
		switch (flag)
		{
		case -1:
			cout << "Ajisai\n";
			break;
		case 0:
			cout << "Tie\n";
			break;
		case 1:
			cout << "Mai\n";
			break;
		}
	}
}