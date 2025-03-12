#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long a[400];
long long tri[400][400][400];
long long memo[400][400];

long long solution(int n, int i, int j)
{
	if (i == j || (j + 1) % n == i)
		return memo[i][j] = 0;
	if (memo[i][j] >= 0)
		return memo[i][j];

	long long vmax = max(solution(n, i, (j + 1) % n), solution(n, (i + n - 1) % n, j));
	for (int k = (j + 1) % n; k != i; k = (k + 1) % n)
	{
		long long v = tri[i][j][k];
		if (k != (j + 1) % n)
			v += solution(n, (k + n - 1) % n, (j + 1) % n);
		if (k != (i + n - 1) % n)
			v += solution(n, (i + n - 1) % n, (k + 1) % n);
		vmax = max(vmax, v);
	}
	return memo[i][j] = vmax;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		memset(memo, -1, sizeof(memo));
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				for (int k = j + 1; k < n; ++k)
				{
					long long v = a[i] * a[j] * a[k];
					tri[i][j][k] = v;
					tri[i][k][j] = v;
					tri[j][i][k] = v;
					tri[j][k][i] = v;
					tri[k][i][j] = v;
					tri[k][j][i] = v;
				}
			}
		}

		long long ret = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != j)
					ret = max(ret, solution(n, i, j));
			}
		}
		cout << ret << "\n";
	}
}