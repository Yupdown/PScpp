#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

map<long long, vector<long long>> um;

int main()
{
	FASTIO();

	int t;
	cin >> t;
	while (t--)
	{
		um.clear();

		long long n, k;
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
		{
			long long v;
			cin >> v;
			um[v % k].push_back(v);
		}

		long long c = 0;
		bool flag = false;
		for (auto& p : um)
		{
			auto& a = p.second;
			sort(a.begin(), a.end());
			if (a.size() & 1)
			{
				if (flag || !(n & 1))
				{
					c = -1;
					break;
				}
				if (a.size() > 1)
				{
					vector<long long> v1, v2;
					v1.push_back(0);
					v2.push_back(0);
					for (int i = 0; i < a.size() - 1; i += 2)
					{
						v1.push_back(v1.back() + (a[i + 1] - a[i]) / k);
						v2.push_back(v2.back() + (a[a.size() - i - 1] - a[a.size() - i - 2]) / k);
					}
					long long cp = INT64_MAX;
					for (int i = 0; i < v1.size(); ++i)
						cp = min(cp, v1[i] + v2[v1.size() - i - 1]);
					c += cp;
				}
				flag = true;
			}
			else
			{
				for (int i = 0; i < a.size() - 1; i += 2)
					c += (a[i + 1] - a[i]) / k;
			}
		}

		cout << c << '\n';
	}
}