#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edges[20001];
int memo[20001];
int result[10001];

vector<vector<int>> ssc_nodes;
stack<int> dfs_nodes;

int dfs(int index)
{
	static int cnt = 0;
	memo[index] = ++cnt;

	dfs_nodes.push(index);

	int res = memo[index];
	for (auto edge : edges[index])
	{
		if (memo[edge] == 0)
			res = min(res, dfs(edge));
		else if (memo[edge] > 0)
			res = min(res, memo[edge]);
	}

	if (res == memo[index])
	{
		vector<int> v;
		int t;
		do
		{
			t = dfs_nodes.top();
			dfs_nodes.pop();

			v.push_back(t);
			memo[t] = -1;
		} while (!dfs_nodes.empty() && t != index);

		ssc_nodes.push_back(v);
	}

	return res;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		edges[-a + 10000].push_back(b + 10000);
		edges[-b + 10000].push_back(a + 10000);
	}

	for (int i = 10000 - n; i <= 10000 + n; ++i)
	{
		if (memo[i] < 0)
			continue;
		dfs(i);
	}

	set<int> s;
	bool flag = true;
	for (auto& v : ssc_nodes)
	{
		s.clear();
		for (int node : v)
		{
			int node_abs = abs(node - 10000);
			if (s.find(node_abs) != s.end())
				flag &= false;
			else
				s.insert(node_abs);
		}
	}

	cout << flag << '\n';
	if (flag)
	{
		memset(result, -1, sizeof(result));
		for (auto iter = ssc_nodes.rbegin(); iter != ssc_nodes.rend(); ++iter)
		{
			for (int node : *iter)
			{
				int node_abs = abs(node - 10000);

				if (result[node_abs] < 0)
					result[node_abs] = node < 10000;
				else
				{
					bool cstate = result[node_abs] == (node > 10000);
					for (int next : edges[node])
					{
						int next_abs = abs(next - 10000);
						if (cstate)
							result[next_abs] = next > 10000;
						else if (result[next_abs] != (next > 10000))
							result[next_abs] = next < 10000;
					}
				}
			}
		}

		for (int i = 0; i < n; ++i)
			cout << result[i + 1] << ' ';
	}
}