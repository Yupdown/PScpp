#include <iostream>

using namespace std;

int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] = node1;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int nodes[1000001];
	for (int i = 0; i < n + 1; ++i)
		nodes[i] = -1;

	while (m-- > 0)
	{
		int q, a, b;
		cin >> q >> a >> b;

		int ra = find_node(nodes, a);
		int rb = find_node(nodes, b);

		switch (q)
		{
		case 0:
			if (ra != rb)
				union_node(nodes, ra, rb);
			break;
		case 1:
			cout << (ra == rb ? "YES\n" : "NO\n");
			break;
		}
	}

	return 0;
}