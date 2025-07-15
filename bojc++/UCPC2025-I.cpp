#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];
vector<set<long long>> v;

void dfs(int x, int y)
{
	pair<int, int> candidates[] =
	{
		make_pair(x + 1, y),
		make_pair(x, y + 1),
		make_pair(x - 1, y),
		make_pair(x, y - 1),
	};
	for (const auto& [xp, yp] : candidates)
	{
		if (xp < 0 || xp >= v.size())
			continue;
		auto it = find(v[xp].begin(), v[xp].end(), yp);
		if (it == v[xp].end())
			continue;
		v[xp].erase(it);
		dfs(xp, yp);
	}
}

int main()
{
	FASTIO();	

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	set<long long>* vv = &v.emplace_back();
	vv->emplace(table[0]);
	for (int i = 1; i < n; ++i)
	{
		if (table[i - 1] > table[i])
			vv = &v.emplace_back();
		vv->emplace(table[i]);
	}

	int rmin = 0;
	vector<set<long long>> vp = v;
	for (int i = 0; i < vp.size(); ++i)
	{
		for (const long long j : vp[i])
		{
			if (v[i].find(j) != v[i].end())
			{
				dfs(i, j);
				rmin++;
			}
		}
	}

	cout << rmin << " " << n;
}