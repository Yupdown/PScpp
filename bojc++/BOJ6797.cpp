#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[20];

int main()
{
	FASTIO();

	int n;
	while (cin >> n && n > 0)
	{
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		int d = 0;
		while (++d <= n)
		{
			bool flag = true;
			for (int i = 0; i + d + 1 < n && flag; ++i)
				flag = table[(i + 1) % n] - table[i] == table[(i + d + 1) % n] - table[(i + d) % n];
			if (flag)
				break;
		}
		cout << (n > 1 ? d : 0) << '\n';
	}
}