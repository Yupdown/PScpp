#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edges[10001];
vector<vector<int>> result;
int memo[10001], cnt;
stack<int> st;

int dfs(int index)
{
	memo[index] = ++cnt;
	st.push(index);

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
			t = st.top();
			st.pop();

			v.push_back(t);
			memo[t] = -1;
		} while (!st.empty() && t != index);

		result.push_back(v);
	}

	return res;
}

int main()
{
	FASTIO();

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
	}

	for (int i = 0; i < v; ++i)
	{
		if (memo[i + 1] == 0)
			dfs(i + 1);
	}

	for (auto& scc : result)
		sort(scc.begin(), scc.end());
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (auto& scc : result)
	{
		for (int node : scc)
			cout << node << " ";
		cout << "-1\n";
	}
}