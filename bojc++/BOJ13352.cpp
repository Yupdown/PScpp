#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
pair<long long, long long> table[100000];

int main()
{
	FASTIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i].first >> table[i].second;
	if (n == 1)
	{
		cout << "success";
		return 0;
	}
	srand(20251011);
	for (int sample = 0; sample < 1000; ++sample)
	{
		auto& lhs = table[rand() % n];
		auto& rhs = table[rand() % n];
		if (lhs == rhs)
			continue;
		pair<long long, long long> lhsp, rhsp;
		int cnt = 0;
		bool flag = true;
		for (int i = 0; i < n && flag; ++i)
		{
			auto dx1 = rhs.first - lhs.first;
			auto dy1 = rhs.second - lhs.second;
			auto dx2 = table[i].first - lhs.first;
			auto dy2 = table[i].second - lhs.second;
			if (dx1 * dy2 - dx2 * dy1 != 0)
			{
				switch (++cnt)
				{
				case 1:
					lhsp = table[i];
					break;
				case 2:
					rhsp = table[i];
					break;
				default:
				{
					auto dx3 = rhsp.first - lhsp.first;
					auto dy3 = rhsp.second - lhsp.second;
					auto dx4 = table[i].first - lhsp.first;
					auto dy4 = table[i].second - lhsp.second;
					if (dx3 * dy4 - dx4 * dy3 != 0)
						flag = false;
				}
				}
			}
		}
		if (flag)
		{
			cout << "success";
			return 0;
		}
	}
	cout << "failure";
}