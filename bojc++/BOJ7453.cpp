#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[4000][4];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cin >> table[i][j];
	}

	vector<int> vab, vcd;
	vab.reserve(n * n);
	vcd.reserve(n * n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			vab.emplace_back(table[i][0] + table[j][1]);
			vcd.emplace_back(table[i][2] + table[j][3]);
		}
	}
	sort(vab.begin(), vab.end());
	sort(vcd.begin(), vcd.end());

	long long ret = 0;
	for (int i = 0, j = 0; i < n * n; ++i)
	{
		if (i < n - 1 && vab[i] == vab[i + 1])
			continue;
		auto [l, r] = equal_range(vcd.begin(), vcd.end(), -vab[i]);
		ret += static_cast<long long>(i - j + 1) * (r - l);
		j = i + 1;
	}

	cout << ret;
}