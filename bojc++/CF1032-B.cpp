#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<int, int> memo[26];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		int n;
		cin >> n >> s;

		for (int i = 0; i < 26; ++i)
			memo[i] = make_pair(INT_MAX, -1);

		for (int i = 0; i < n; ++i)
		{
			int index = s[i] - 'a';
			memo[index].first = min(memo[index].first, i);
			memo[index].second = max(memo[index].second, i);
		}

		bool flag = false;
		for (int i = 1; i < n - 1 && !flag; ++i)
		{
			int index = s[i] - 'a';
			if (i > memo[index].first || i < memo[index].second)
				flag = true;
		}

		cout << (flag ? "Yes" : "No") << "\n";
	}
}