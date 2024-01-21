#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long memo[1 << 20];

int main()
{
	FASTIO();

	for (int i = 1; i <= 1000000; ++i)
	{
		for (int j = i; j <= 1000000; j += i)
			memo[j] += i;
	}
	for (int i = 1; i <= 1000000; ++i)
		memo[i] += memo[i - 1];

	int t, n;
	cin >> t;

	while (t-- > 0)
	{
		cin >> n;
		cout << memo[n] << '\n';
	}
}