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
		string l, r;
		cin >> l >> r;
		int p = l.size();
		for (int i = 0; i < l.size(); ++i)
		{
			if (l[i] != r[i])
			{
				p = i;
				break;
			}
		}
		if (p == l.size() || l[p] + 1 < r[p])
			cout << p * 2 << "\n";
		else
		{
			int lp = distance(l.begin(), find_if_not(l.begin() + p + 1, l.end(), [](char c) { return c == '9'; }));
			int rp = distance(r.begin(), find_if_not(r.begin() + p + 1, r.end(), [](char c) { return c == '0'; }));
			cout << p * 2 + 1 + min(lp - p - 1, rp - p - 1) << "\n";
		}
	}
}