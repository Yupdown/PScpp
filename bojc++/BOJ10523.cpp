#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
pair<long long, long long> table[100000];	

int main()
{
	FASTIO();
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;
	if (n == 1)
	{
		cout << "possible";
		return 0;
	}
	srand(20251003);
	for (int sample = 0; sample < 1000; ++sample)
	{
		auto& lhs = table[rand() % n];
		auto& rhs = table[rand() % n];
		if (lhs == rhs)
			continue;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			auto dx1 = rhs.first - lhs.first;
			auto dy1 = rhs.second - lhs.second;
			auto dx2 = table[i].first - lhs.first;
			auto dy2 = table[i].second - lhs.second;
			if (dx1 * dy2 - dx2 * dy1 == 0)
				cnt++;
		}
		if (cnt * 100 >= n * p)
		{
			cout << "possible";
			return 0;
		}
	}
	cout << "impossible";
}