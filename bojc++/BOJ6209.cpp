#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[50000];

int solution(int d, int n, int x)
{
	int p = 0, r = 0;
	for (int i = 0; i < n; ++i)
	{
		if (table[i] - p < x)
			++r;
		else
			p = table[i];
	}
	return r + (d - p < x);
}

int main()
{
	FASTIO();

	int d, n, m;
	cin >> d >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	sort(table, table + n);
	int x = 0;
	for (int dx = 1 << 29; dx; dx >>= 1)
	{
		if (solution(d, n, x + dx) <= m)
			x += dx;
	}
	cout << x;
}