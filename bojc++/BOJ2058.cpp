#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int itov[200];
map<int, int> vtoi;
vector<int> edges[200];
int memo[200][2];

int solution(int node_parent, int node, bool flag)
{
	if (memo[node][flag] >= 0)
		return memo[node][flag];
	int ret = 0;
	for (int node_next : edges[node])
	{
		if (node_next != node_parent)
			ret += solution(node, node_next, !flag);
	}
	return memo[node][flag] = flag ? max(ret + itov[node], solution(node_parent, node, false)) : ret;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		itov[i] = v;
		vtoi[v] = i;
	}
	vector<int> delta;
	for (int i = 0; i < m; ++i)
		cin >> delta.emplace_back();
	for (const auto& [v, i] : vtoi)
	{
		for (int d : delta)
		{
			if (vtoi.find(v + d) != vtoi.end())
				edges[i].push_back(vtoi[v + d]);
			if (vtoi.find(v - d) != vtoi.end())
				edges[i].push_back(vtoi[v - d]);
		}
	}

	memset(memo, -1, sizeof(memo));
	cout << solution(-1, 0, true);
}