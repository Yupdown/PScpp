#include <bits/stdc++.h>

using namespace std;

int flood[312500];
queue<int> q;

int main()
{
	int n, k;
	cin >> n >> k;

	int nmax = 0;
	q.push(n);
	while (k-- > 0)
	{
		nmax = 0;
		memset(flood, 0, sizeof(flood));

		int size = q.size();
		while (size-- > 0)
		{
			int n0 = q.front();
			q.pop();

			for (int d = 1; d <= n0; d *= 10)
			{
				for (int e = d * 10; e <= n0; e *= 10)
				{
					int va = n0 / d % 10;
					int vb = n0 / e % 10;

					if (e * 10 > n0 && va == 0)
						continue;

					int np = n0 + va * (e - d) + vb * (d - e);

					if (flood[np / 32] & (1 << (np % 32)))
						continue;

					q.push(np);
					flood[np / 32] |= 1 << (np % 32);
					nmax = max(nmax, np);
				}
			}
		}
	}

	cout << (q.size() > 0 ? nmax : -1);
}