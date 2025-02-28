#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<tuple<int, int, int>> act;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	for (int x = 0; x < t; ++x)
	{
		act.clear();

		int ac, aj;
		cin >> ac >> aj;
		for (int i = 0; i < ac; ++i)
		{
			int a, b;
			cin >> a >> b;
			act.emplace_back(a, b, 0);
		}
		for (int i = 0; i < aj; ++i)
		{
			int a, b;
			cin >> a >> b;
			act.emplace_back(a, b, 1);
		}

		sort(act.begin(), act.end());
		int na = act.size();
		int tc = 0;
		int tj = 0;
		int tr = 0;
		int ret = 0;

		priority_queue<int> pqc;
		priority_queue<int> pqj;

		for (int i = 0; i < na; ++i)
		{
			const auto& [a, b, c] = act[i];
			const auto& [ap, bp, cp] = act[(i + 1) % na];
			(c ? tc : tj) += b - a;
			int d = (ap + 1440 - b) % 1440;
			if (c == cp)
			{
				(c ? tc : tj) += d;
				(c ? pqj : pqc).push(d * 2);
			}
			else
			{
				tr += d;
				ret++;
			}
		}

		auto& pq = tc < tj ? pqc : pqj;
		while (!pq.empty() && abs(tc - tj) > tr)
		{
			tr += pq.top();
			pq.pop();
			ret += 2;
		}

		cout << "Case #" << x + 1 << ": " << ret << "\n";
	}
}