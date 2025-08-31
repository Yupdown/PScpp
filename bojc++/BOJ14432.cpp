#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[100000];
vector<int> edges[100000];

long long solution(int node_curr, int node_parent)
{
	long long ret = 0;
	long long maxv = 0;
	for (int node_next : edges[node_curr])
	{
		if (node_next == node_parent)
			continue;
		ret += solution(node_next, node_curr);
		maxv = max(maxv, table[node_next]);
	}
	table[node_curr] = max(table[node_curr] - maxv, 0LL);
	for (int node_next : edges[node_curr])
		table[node_next] = max(table[node_next] - maxv, 0LL);
	return ret + maxv;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a - 1].emplace_back(b - 1);
		edges[b - 1].emplace_back(a - 1);
	}

	cout << solution(0, -1) + table[0];
}