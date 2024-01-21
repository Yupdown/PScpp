#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char str[3][32];

int main()
{
	FASTIO();

	int t, n;
	cin >> t;

	while (t-- > 0)
	{
		cin >> n;
		cin >> str[0] >> str[1] >> str[2];

		bool flag = false;
		for (int i = 0; i < n && !flag; ++i)
		{
			if (str[0][i] != str[2][i] && str[1][i] != str[2][i])
				flag = true;
		}

		cout << (flag ? "YES" : "NO") << '\n';
	}
}