#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[1 << 17];

vector<int> cand;

void func(int v)
{
	if (v > 100000)
		return;
	table[v] = 1;
	for (auto it : cand)
	{
		if (it == 1)
			continue;
		func(v * it);
	}
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	for (int i = 1; i < 32; ++i)
	{
		int v = 0;
		for (int j = 0; j < 6; ++j)
			v += pow(10, j) * ((i >> j) & 1);
		cand.push_back(v);
	}

	func(1);

	while (t-- > 0)
	{
		int n;
		cin >> n;
		cout << (table[n] ? "YES" : "NO") << '\n';
	}
}