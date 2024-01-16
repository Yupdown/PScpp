#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	string s;
	int n, m, pi[10];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> pi[i];
	cin >> m;

	if (n <= 1)
	{
		cout << '0';
		return 0;
	}

	int imin = 1;
	for (int i = 2; i < n; ++i)
	{
		if (pi[i] <= pi[imin])
			imin = i;
	}

	if (pi[imin] > m)
	{
		cout << '0';
		return 0;
	}

	s.push_back(imin + '0');
	m -= pi[imin];
	imin = pi[imin] <= pi[0] ? imin : 0;
	while (m >= pi[imin])
	{
		s.push_back(imin + '0');
		m -= pi[imin];
	}

	for (auto iter = s.begin(); iter != s.end() && m > 0; ++iter)
	{
		int cpi = *iter - '0';
		int ip = 0;
		for (int i = 0; i < n; ++i)
		{
			if (pi[i] - pi[cpi] <= m)
				ip = i;
		}
		*iter = ip + '0';
		m -= pi[ip] - pi[cpi];
	}

	cout << s;
}