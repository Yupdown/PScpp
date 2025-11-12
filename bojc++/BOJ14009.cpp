#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];

int main()
{
	FASTIO();
	long long n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	long long ret = n, j = 0;
	if (n > 1 && table[1] - table[0] == 0)
		j = 1;
	for (long long i = 1; i < n - 1; ++i)
	{
		if ((table[i + 1] - table[i]) * (table[i] - table[i - 1]) >= 0)
		{
			ret += (i - j) * (i - j + 1) / 2;
			j = table[i + 1] - table[i] == 0 ? i + 1 : i;
		}
	}
	ret += (n - 1 - j) * (n - j) / 2;
	cout << ret;
}