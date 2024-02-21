#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char buffer[16];
int table[50];

int comb(int n, int k, int j, int mask)
{
	int ret = 0;
	if (k == 0)
	{
		for (int i = 0; i < n; ++i)
			ret += (mask & table[i]) == table[i];
	}
	else
	{
		while (j < 26)
		{
			if (!(mask >> j & 1))
				ret = max(ret, comb(n, k - 1, j + 1, mask | 1 << j));
			++j;
		}
	}
	return ret;
}

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;
		for (char* ptr = buffer; *ptr != 0; ++ptr)
			table[i] |= 1 << *ptr - 'a';
	}

	cout << (k > 4 ? comb(n, k - 5, 0, 532741) : 0);
}