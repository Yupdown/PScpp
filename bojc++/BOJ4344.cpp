#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int c;
	cin >> c;

	while (c-- > 0)
	{
		int n;
		cin >> n;

		int a[1000];
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}

		int c = 0;
		for (int i = 0; i < n; i++)
			c += a[i] * n > sum ? 1 : 0;

		printf("%.03lf%%\n", round(100000.0 * c / n) * 0.001);
	}

	return 0;
}