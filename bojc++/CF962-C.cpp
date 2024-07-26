#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char a[1 << 18];
char b[1 << 18];

int acca[1 << 18][26];
int accb[1 << 18][26];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n, q;
		cin >> n >> q;
		cin >> a >> b;

		for (char j = 0; j < 26; ++j)
		{
			acca[0][j] = 0;
			accb[0][j] = 0;
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				acca[i + 1][j] = acca[i][j];
				accb[i + 1][j] = accb[i][j];
			}
			acca[i + 1][a[i] - 'a']++;
			accb[i + 1][b[i] - 'a']++;
		}

		for (int i = 0; i < q; ++i)
		{
			int l, r;
			cin >> l >> r;

			int ret = 0;
			for (int j = 0; j < 26; ++j)#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		cout << n / 4 + (n % 4) / 2 << '\n';
	}
}
				ret += abs((acca[r][j] - acca[l - 1][j]) - (accb[r][j] - accb[l - 1][j]));
			cout << ret / 2 << '\n';
		}
	}
}