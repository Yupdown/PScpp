#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int temp[200000][26];

bool check(string_view s, int n, int k)
{
	memset(temp, 0, sizeof(temp));
	for (int i = k; i < n; ++i)
		temp[i % k][s[i] - 'a'] += 1;
	
	bool flag = false;
	for (int i = 0; i < k; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (temp[i][j] == 0 || temp[i][j] == n / k)
				continue;
			if (!flag && (temp[i][j] == 1 || temp[i][j] == n / k - 1))
			{
				flag = true;
				continue;
			}
			return false;
		}
	}

	return true;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		string s;
		cin >> n >> s;

		int k = n;
		for (int i = 1; i * i <= n; ++i)
		{
			if (n % i != 0)
				continue;
			if (check(s, n, i))
				k = min(k, i);
			if (check(s, n, n / i))
				k = min(k, n / i);
		}
		cout << k << '\n';
	}
}