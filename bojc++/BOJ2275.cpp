#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int flags[200001];

int conflicts(int t, int x)
{
	int c = 0;
	while (t < 200001)
	{
		c += flags[t];
		t += x;
	}
	return c;
}

int main()
{
	FASTIO();

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
	{
		int s, d;
		cin >> s >> d;
		for (int j = s; j <= s + d; ++j)
			flags[j] = true;
	}

	pair<int, int> ret{ 0, INT_MAX };
	for (int t = 0; t <= 480; ++t)
	{
		int c = conflicts(t, x);
		if (c < ret.second)
			ret = { t, c };
	}

	cout << ret.first << ' ' << ret.second;
}