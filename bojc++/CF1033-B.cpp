#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long dx[1000];
long long dy[1000];
long long x[1000];
long long y[1000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		long long n, s;
		cin >> n >> s;
		for (int i = 0; i < n; ++i)
			cin >> dx[i] >> dy[i] >> x[i] >> y[i];
		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			if ((x[i] == y[i] && dx[i] * dy[i] == 1) || (x[i] == s - y[i] && dx[i] * dy[i] == -1))
				ret += 1;
		}
		cout << ret << "\n";
	}
}