#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[100000];

int main()
{
	FASTIO();

	int k;
	cin >> k;
	int r = 0;
	for (int i = 0; i < k; ++i)
	{
		int v;
		cin >> v;
		r += v / k;
		table[i] = v % k;
	}
	sort(table, table + k, greater<int>());
	int rmin = r + k;
	for (int i = 0; i < k; ++i)
		rmin = min(rmin, r + i + table[i]);
	cout << rmin;
}