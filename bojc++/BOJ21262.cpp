#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;

	if (!k)
		cout << -1;
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			if (i <= k)
				cout << max(1, k % 2 != i % 2 ? i + 1 : i - 1);
			else
				cout << i;
			if (i < n)
				cout << ' ';
		}
	}
}