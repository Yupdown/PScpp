#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[100000];

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;

	int r = INT_MIN;
	int c = 0;
	for (int i = 0; i < n; ++i) {
		cin >> table[i];
		c += table[i];
		if (i >= k)
			c -= table[i - k];
		if (i + 1 >= k)
			r = max(r, c);

	}

	cout << r;
}