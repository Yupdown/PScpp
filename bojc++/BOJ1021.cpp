#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int mi[50];

int main()
{
	FASTIO();

	int n, m, p = 1, r = 0;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
		cin >> mi[i];

	for (int i = 0; i < m; ++i)
	{
		int a = min(mi[i], p);
		int b = max(mi[i], p);

		r += min(b - a, a + n - i - b);
		p = mi[i];

		for (int j = i + 1; j < m; ++j)
			mi[j] = mi[j] > mi[i] ? mi[j] - 1 : mi[j];
	}

	cout << r << '\n';
}