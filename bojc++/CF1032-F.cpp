#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];
long long psum[200000];
map<long long, long long> cnts;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		cnts.clear();

		long long n, s, x;
		cin >> n >> s >> x;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		psum[0] = table[0];
		for (int i = 1; i < n; ++i)
			psum[i] = psum[i - 1] + table[i];
		
		long long ret = 0;
		bool flag = false;
		cnts[0]++;
		for (int p = 0, q = 0; q < n; ++q)
		{
			if (table[q] > x)
			{
				flag = false;
				cnts.clear();
				p = q;
			}
			else
			{
				if (table[q] == x)
				{
					flag = true;
					while (p < q)
						cnts[psum[p++]]++;
				}
				if (flag)
					ret += cnts[psum[q] - s];
			}
		}

		cout << ret << "\n";
	}
}