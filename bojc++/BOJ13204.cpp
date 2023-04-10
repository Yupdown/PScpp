#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

inline long long perc(long long t, long long s)
{
	return (t * 1000000 / s + 5) / 10;
}

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t-- > 0)
	{
		char buffer[8];
		cin >> buffer;

		long long value = 0, base = 1;
		for (int i = strlen(buffer) - 1; i >= 0; --i)
		{
			if (buffer[i] == '.')
				continue;
			value += (buffer[i] - '0') * base;
			base *= 10;
		}

		long long samp = 0;
		while (++samp <= 100000)
		{
			long long rdiv = samp * value / 100000;
			if (perc(rdiv, samp) == value || perc(rdiv + 1, samp) == value)
				break;
		}

		cout << samp << '\n';
	}
}