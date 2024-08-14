#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

long long table[200000];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> table[i];
		for (int i = 1; i < n; ++i)
			table[i] += table[i - 1];

		string s;
		cin >> s;

		queue<int> l, r;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == 'L')
				l.push(i);
			if (s[n - i - 1] == 'R')
				r.push(n - i - 1);
		}

		long long sum = 0;
		while (!l.empty() && !r.empty())
		{
			if (r.front() < l.front())
				break;
			sum += table[r.front()] - (l.front() > 0 ? table[l.front() - 1] : 0);
			l.pop();
			r.pop();
		}
		cout << sum << '\n';
	}
}