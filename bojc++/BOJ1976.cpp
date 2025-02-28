#include <iostream>

using namespace std;

int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

void union_node(int* nodes, int node0, int node1)
{
	nodes[node1] = node0;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int nodes[200];

	for (int i = 0; i < n; ++i)
		nodes[i] = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int v;
			cin >> v;
			if (!v)
				continue;

			int pi = find_node(nodes, i);
			int pj = find_node(nodes, j);

			if (pi != pj)
				union_node(nodes, pi, pj);
		}
	}

	bool result = true;
	int from, to;
	cin >> from;
	for (int i = 1; i < m && result; ++i)
	{
		cin >> to;

		int pi = find_node(nodes, from - 1);
		int pj = find_node(nodes, to - 1);

		if (pi != pj)
			result = false;
		from = to;
	}

	cout << (result ? "YES" : "NO") << endl;
	return 0;
}