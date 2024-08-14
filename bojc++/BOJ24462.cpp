#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long ti[1000];
long long ki[1000];

int main()
{
	FASTIO();

	long long n, d;
	cin >> n >> d;
	for (int i = 0; i < n; ++i)
		cin >> ti[i] >> ki[i];

	pair<int, int> p;
	long long vmax = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			long long k = lcm(ki[i], ki[j]);
			long long tk = (max(ti[i], ti[j]) + k - 1) / k * k;
			long long iv = d / ki[i] - ti[i] / ki[i] + 1;
			long long jv = d / ki[j] - ti[j] / ki[j] + 1;
			long long kv = d / k - tk / k + 1;
			long long v = max(0ll, iv) + max(0ll, jv) - max(0ll, kv);
			if (v > vmax)
			{
				vmax = v;
				p = { i + 1, j + 1 };
			}
		}
	}

	cout << p.first << ' ' << p.second << '\n' << vmax;
}