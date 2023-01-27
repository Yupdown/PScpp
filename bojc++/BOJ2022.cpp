#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

int64 f[100'000];

int main()
{
	FASTIO();

	int n;
	int64 k, c = 1;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> f[i];
	cin >> k;

	while (c < n)
	{
		int64 lhs = f[c - 1] - k * c;
		int64 rhs = f[c] - k * (c + 1);

		if ((lhs <= 0 || rhs <= 0) && (lhs >= 0 || rhs >= 0))
			break;

		++c;
	}

	cout << (n == 1 && f[0] == k || c < n ? 'T' : 'F');
}