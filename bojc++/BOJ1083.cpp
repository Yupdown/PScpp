#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[50];

int main()
{
	FASTIO();

	int n, s;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	cin >> s;

	int c = 0;
	while (s > 0 && c < n) {
		int t = c;
		for (int i = c + 1; i < n && i - c <= s; ++i) {
			if (table[i] > table[t])
				t = i;
		}
		for (int i = c; i < t; ++i)
			swap(table[i], table[t]);
		s -= t - c;
		++c;
	}

	for (int i = 0; i < n; ++i)
		cout << table[i] << ' ';
}