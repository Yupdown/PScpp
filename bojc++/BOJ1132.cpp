#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

int main()
{
	FASTIO();

	int n;
	char input[50][13];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> input[i];

	int64 mask[10] = { 0 };
	bool flag[10] = { 0 };
	for (int i = 0; i < n; ++i)
	{
		int64 add = 1;
		int len = strlen(input[i]);
		for (int j = len - 1; j >= 0; --j, add *= 10)
			mask[input[i][j] - 'A'] += add;
		flag[input[i][0] - 'A'] = true;
	}

	int64 res = 0;
	for (int i = 0; i < 10; ++i)
	{
		int min_index = -1;
		for (int j = 0; j < 10 - i; ++j)
		{
			if (i > 0 || !flag[j])
				min_index = min_index < 0 || mask[j] < mask[min_index] ? j : min_index;
		}
		res += mask[min_index] * i;
		swap(mask[min_index], mask[9 - i]);
	}

	cout << res << endl;
	return 0;
}