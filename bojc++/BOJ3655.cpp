#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[128];

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		int n, r = 0;
		string s;
		cin >> n >> s;

		fill(begin(memo), end(memo), n);
		for (int i = n - 1; i >= 0; --i)
		{
			int c = s[i];
			if (memo[c] < n)
				r += --memo[c] - i;
			else
				memo[c] = i;
		}
		cout << r * 5 << '\n';
	}
}