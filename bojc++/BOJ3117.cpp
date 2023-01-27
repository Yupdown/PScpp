#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int start[100000];
int table[100000][30];

int main()
{
	FASTIO();

	int n, k, m;
	cin >> n >> k >> m;

	for (int i = 0; i < n; ++i)
		cin >> start[i];
	for (int i = 0; i < k; ++i)
		cin >> table[i][0];

	for (int i = 1; i < 30; ++i) {
		for (int j = 0; j < k; ++j)
			table[j][i] = table[table[j][i - 1] - 1][i - 1];
	}

	for (int i = 0; i < n; ++i) {
		int r = start[i];
		for (int j = 0; j < 30; ++j) {
			if (~(m - 1) & 1 << j)
				continue;
			r = table[r - 1][j];
		}
		cout << r << ' ';
	}
}