#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[1000][3];

int main()
{
	FASTIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i][0] >> table[i][1] >> table[i][2];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < 3; ++j)
			table[i][j] += min(table[i - 1][(j + 1) % 3], table[i - 1][(j + 2) % 3]);
	}
	cout << min(min(table[n - 1][0], table[n - 1][1]), table[n - 1][2]);
}