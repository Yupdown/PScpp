#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int64_t table[26];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	char buffer[16];
	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;
		int len = strlen(buffer);

		int64_t base = 1;
		for (int j = len - 1; j >= 0; --j)
		{
			table[buffer[j] - 'A'] += base;
			base *= 10;
		}
	}

	sort(begin(table), end(table), greater<int64_t>());
	int64_t sum = 0;
	for (int i = 0; i < 10; ++i)
		sum += table[i] * (9 - i);

	cout << sum;
}