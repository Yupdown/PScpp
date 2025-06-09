#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

set<pair<int, int>> memo;

int main()
{
	FASTIO();

	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		memo.emplace(p);
	}
	int ret = 0;
	for (const auto& p : memo)
	{
		if (memo.find(make_pair(p.first + a, p.second)) == memo.end())
			continue;
		if (memo.find(make_pair(p.first, p.second + b)) == memo.end())
			continue;
		if (memo.find(make_pair(p.first + a, p.second + b)) == memo.end())
			continue;
		ret++;
	}
	cout << ret;
}