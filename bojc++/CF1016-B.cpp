#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int c1 = 0;
		int lp = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] != '0')
			{
				c1++;
				lp = i;
			}
		}
		cout << c1 + s.length() - lp - 2 << "\n";
	}
}