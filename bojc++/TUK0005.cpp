#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> table[100000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; ++i)
		table[i].second = i + 1;

	for (int i = 0; i < m; ++i)
	{
		int v;
		cin >> v;
		table[v - 1].first += 1;
	}

	sort(table, table + n);
	cout << table[n - 3].second;
}