#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[3000001];

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	while (k--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		for (int i = 1; i <= y; ++i)
			memo[(static_cast<long long>(a) * i + b) % n] += x;
	}
	for (int i = 0; i < n; ++i)
	{
		memo[i + 1] += max(memo[i] - 1, 0);
		memo[i] = min(memo[i], 1);
	}
	int r = 0;
	k = memo[n];
	while (k > 0 || memo[r])
		k -= 1 - memo[r++];
	cout << r;
}