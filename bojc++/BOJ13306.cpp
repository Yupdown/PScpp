#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int nodes[200001];
int queries[400000][3];
stack<bool> s_result;

int find_node(int* nodes, int node)
{
	return nodes[node] > 0 ? (nodes[node] = find_node(nodes, nodes[node])) : node;
}

int main()
{
	FASTIO();

	int n, q;
	cin >> n >> q;

	for (int i = 1; i < n; ++i)
		cin >> nodes[i + 1];

	for (int i = 0; i < n + q - 1; ++i)
	{
		cin >> queries[i][0];
		switch (queries[i][0])
		{
		case 0:
			cin >> queries[i][1];
			queries[i][2] = nodes[queries[i][1]];
			nodes[queries[i][1]] = 0;
			break;
		case 1:
			cin >> queries[i][1] >> queries[i][2];
			break;
		}
	}

	for (int i = n + q; i >= 0; --i)
	{
		switch (queries[i][0])
		{
		case 0:
			nodes[queries[i][1]] = queries[i][2];
			break;
		case 1:
			s_result.push(find_node(nodes, queries[i][1]) == find_node(nodes, queries[i][2]));
			break;
		}
	}

	while (!s_result.empty())
	{
		bool result = s_result.top();
		s_result.pop();
		cout << (result ? "YES" : "NO") << "\n";
	}
}