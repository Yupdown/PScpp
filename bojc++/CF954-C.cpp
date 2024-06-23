#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char s[100001];
int ind[100000];
char c[100001];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;
		cin >> s;
		for (int i = 0; i < m; ++i)
			cin >> ind[i];
		cin >> c;

		sort(ind, ind + m);
		sort(c, c + m);

		for (int i = 0, j = 0; i < m; ++i)
		{
			if (i == m - 1 || ind[i] < ind[i + 1])
				s[ind[i] - 1] = c[j++];
		}

		cout << s << '\n';
	}
}