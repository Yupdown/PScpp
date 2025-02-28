#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int a[1'000'000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a + n);

	int l = -8192, c = 0;
	for (int i = 0; i < n; ++i)
	{
		if (l + 100 <= a[i])
		{
			++c;
			l = a[i];
		}
	}

	cout << c << ' ';

	for (int i = 0; i < m; ++i)
		cin >> a[i];

	sort(a, a + m);

	l = -8192, c = 0;
	for (int i = 0; i < m; ++i)
	{
		if (l + 360 <= a[i])
		{
			++c;
			l = a[i];
		}
	}

	cout << c;
}