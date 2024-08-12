#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int xi[100000];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int s, n;
		cin >> s >> n;
		for (int i = 0; i < n; ++i)
			cin >> xi[i];
		
		vector<int> c(s);
		vector<bool> r(s);
		int cf = 0;
		for (int q = 0; q < n + s; ++q)
		{
			if (q >= s)
			{
				if (--c[xi[q - s] - 1] == 1)
					--cf;
			}
			if (q < n)
			{
				if (++c[xi[q] - 1] == 2)
					++cf;
			}
			if (cf)
				r[q % s] = true;
		}

		cout << count(r.begin(), r.end(), false) << '\n';
	}
}