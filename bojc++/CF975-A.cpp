#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[100];

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
			cin >> table[i];
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			int l = i;
			int r = n - i - 1;
			ret = max(ret, table[i] + l / 2 + r / 2 + 1);
		}
		cout << ret << '\n';
	}
}