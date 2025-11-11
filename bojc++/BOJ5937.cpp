#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
vector<int> edges[100002];
int indirect[100002];
int memo[100002];

int main()
{
	FASTIO();
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int ai, bi;
		cin >> ai >> bi;
		edges[ai].emplace_back(bi);
		indirect[bi]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (indirect[i] == 0)
		{
			q.emplace(i);
			memo[i] = 1;
		}
	}
	int target = q.size();
	vector<int> ret;
	while (!q.empty())
	{
		int node_curr = q.front();
		q.pop();
		if (edges[node_curr].size() != 1)
			break;
		for (int node_next : edges[node_curr])
		{
			memo[node_next] += memo[node_curr];
			if (--indirect[node_next] == 0)
			{
				if (memo[node_next] == target)
					ret.emplace_back(node_next);
				q.emplace(node_next);
			}
		}
	}
	sort(ret.begin(), ret.end());
	for (int node : ret)
		cout << node << '\n';
}