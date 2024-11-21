#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		long long n, k;
		cin >> n >> k;

		if (k == 1)
			cout << n << '\n';
		else
		{
			vector<long long> v;
			long long c = k;
			while (c <= n)
			{
				v.push_back(c);
				c *= k;
			}
			long long r = 0;
			while (n >= k)
			{
				auto iter = v.crbegin();
				while (*iter > n)
					++iter;
				n -= *iter;
				++r;
			}
			cout << r + n << '\n';
		}
	}
}