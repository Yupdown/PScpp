#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	for (int c = 0; c < t; ++c)
	{
		int k;
		string s;
		cin >> s >> k;
		int cnt = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '-' && i + k <= s.size())
			{
				for (int j = i; j < i + k; ++j)
					s[j] = s[j] == '+' ? '-' : '+';
				++cnt;
			}
		}
		cout << "Case #" << c + 1 << ": ";
		if (find(s.begin(), s.end(), '-') != s.end())
			cout << "IMPOSSIBLE\n";
		else
			cout << cnt << '\n';
	}
}