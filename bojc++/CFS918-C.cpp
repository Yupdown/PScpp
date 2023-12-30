#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		long long sum = 0LL;

		for (int i = 0; i < n; ++i)
		{
			long long v;
			cin >> v;
			sum += v;
		}

		double div;
		double mod = modf(sqrt(sum), &div);
		cout << (mod == 0 ? "YES" : "NO") << '\n';
	}
}