#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long table[1 << 18];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> table[i];

		bool flag = false;
		long long s = 0LL;
		set<long long> m;
		m.insert(0LL);
		for (int i = 0; i < n; ++i)
		{
			s += table[i] * (i % 2 ? -1LL : 1LL);
			if (m.find(s) != m.end())
				flag = true;
			m.insert(s);
		}

		cout << (flag ? "YES" : "NO") << '\n';
	}
}