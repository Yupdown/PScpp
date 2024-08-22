#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

int64 pow(int64 x, int64 y, int64 m)
{
	if (!y)
		return 1;
	int64 p = pow(x * x % m, y >> 1, m);
	if (y & 1)
		return p * x % m;
	return p;
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	int64 ret = 0;
	for (int i = 0; i < n; ++i)
	{
		int64 k;
		cin >> k;
		ret += pow(2, k, 1000000007);
	}
	cout << ret % 1000000007;
}