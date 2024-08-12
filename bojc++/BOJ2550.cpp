#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[10001][2];
int in[10000];
int memo[10000];
int el[10000];

int main()
{
	FASTIO();
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		table[v][0] = i;
		table[i][1] = v;
	}

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		in[n - i - 1] = table[v][0];
	}

	for (int i = 0; i < n; ++i)
	{
		pair vmax{ 0, -1 };
		for (int j = 0; j < i; ++j)
		{
			if (in[i] < in[j] && memo[j] >= vmax.first)
				vmax = { memo[j], j };
		}
		memo[i] = vmax.first + 1;
		el[i] = vmax.second;
	}

	int r = distance(memo, max_element(memo, memo + n));
	vector<int> ret;
	for (; r >= 0; r = el[r])
		ret.push_back(table[in[r]][1]);
	sort(ret.begin(), ret.end());

	cout << ret.size() << '\n';
	for (int r : ret)
		cout << r << ' ';
}