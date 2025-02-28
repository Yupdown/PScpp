#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[100001];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	int vmax = 0;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		vmax = max(vmax, ++table[v]);
	}

	cout << (vmax * 2 <= n + 1 ? "YES" : "NO");
}