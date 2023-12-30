#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int height[1000000];

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> height[i];

	int x = 0;
	for (int dx = 1 << 30; dx > 0; dx >>= 1)
	{
		long long sum = 0ll;
		for (int i = 0; i < n; ++i)
			sum += max<long long>(height[i] - x - dx, 0ll);
		if (sum >= static_cast<long long>(m))
			x += dx;
	}

	cout << x;
}