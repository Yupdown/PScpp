#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	int v0min = 1000;
	int v1min = 1000;

	for (int i = 0; i < m; ++i)
	{
		int v0, v1;
		cin >> v0 >> v1;

		v0min = min(v0min, v0);
		v1min = min(v1min, v1);
	}

	cout << min(n / 6 * min(v0min, v1min * 6) + n % 6 * v1min, (n / 6 + 1) * v0min) << '\n';
}