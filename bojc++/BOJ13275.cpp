#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[1 << 18];

int main()
{
	FASTIO();

	string s;
	cin >> s;

	size_t n = s.size();
	s.resize(n * 2 + 1);
	s[n * 2] = ' ';
	for (int i = n - 1; i >= 0; --i)
	{
		s[i * 2 + 1] = s[i];
		s[i * 2] = ' ';
	}
	n = s.size();

	int p = -1;
	int r = -1;
	for (int i = 0; i < n; ++i)
	{
		if (i > r)
		{
			for (p = i, r = i; r < n && r <= 2 * p && s[r] == s[2 * p - r]; ++r);
			memo[i] = --r - p;
		}
		else
		{
			int ip = 2 * p - i;
			if (memo[ip] < r - i)
				memo[i] = memo[ip];
			else if (memo[i] > r - i)
				memo[i] = r - i;
			else
			{
				for (p = i; r < n && r <= 2 * p && s[r] == s[2 * p - r]; ++r);
				memo[i] = --r - p;
			}
		}
	}

	cout << *max_element(memo, memo + n);
}