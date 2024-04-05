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
		int n, c = 0;
		cin >> n;

		map<int, int> s;
		for (int i = 0; i < n; ++i)
		{
			int v;
			cin >> v;
			auto iter_find = s.find(v);
			if (iter_find != s.end() && iter_find->second > 0)
			{
				iter_find->second -= 1;
				++c;
			}
			else
			{
				auto iter = s.find(~v & 2147483647);
				if (iter == s.end())
					s[~v & 2147483647] = 0;
				s[~v & 2147483647] += 1;
			}
		}

		cout << n - c << '\n';
	}
}