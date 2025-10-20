#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long memo[1000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	long long ret = 0;
	int base = 0;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		v %= m;
		base = (base + m - v) % m;
		memo[(base + v) % m]++;
		ret += memo[base];
	}
	cout << ret;
}