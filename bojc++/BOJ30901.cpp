#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;
char table[7][25];

double solution(int d, int h, int i, int n)
{
	static int memo[24]{};
	double ret = 0;
	if (n >= d)
	{
		int temp[24];
		memcpy(temp, memo, sizeof(temp));
		sort(temp, temp + 24, greater<int>());
		for (int j = 0, s = 0; j < 24; ++j)
		{
			s += temp[j];
			if (j + 1 >= h)
				ret = max(ret, s / static_cast<double>(n * (j + 1)));
		}
	}
	for (int j = i + 1; j < 7; ++j)
	{
		for (int k = 0; k < 24; ++k)
			memo[k] += table[j][k] == '.';
		ret = max(ret, solution(d, h, j, n + 1));
		for (int k = 0; k < 24; ++k)
			memo[k] -= table[j][k] == '.';
	}
	return ret;
}

int main()
{
	FASTIO();
	PRECISION(16);

	int d, h;
	for (int i = 0; i < 7; ++i)
		cin >> table[i];
	cin >> d >> h;
	cout << solution(d, h, -1, 0);
}