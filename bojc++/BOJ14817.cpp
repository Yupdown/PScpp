#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// table[i][j] -> the number of times customer i chooses seat j
int table[1024][1024];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	
	for (int ti = 1; ti <= t; ++ti)
	{
		memset(table, 0, sizeof(table));

		int n, c, m;
		cin >> n >> c >> m;
		for (int i = 0; i < m; ++i)
		{
			int p, b;
			cin >> p >> b;
			table[b - 1][p - 1] += 1;
		}
		int z = 0, y = max(accumulate(table[0], table[0] + n, 0), accumulate(table[1], table[1] + n, 0));
		for (int i = 0; i < n; ++i)
			(i ? z : y) += max(0, table[0][i] + table[1][i] - y);
		cout << "Case #" << ti << ": " << y << " " << z << "\n";
	}
}