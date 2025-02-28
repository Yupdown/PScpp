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
	int n, m;
	cin >> n >> m;

	int nodes[500000];
	for (int i = 0; i < n; i++)
		nodes[i] = -1;

	int result = 0;
	for (int i = 0; i < m; i++)
	{
		int ia, ib;
		cin >> ia >> ib;

		int rootA = find_node(nodes, ia);
		int rootB = find_node(nodes, ib);
		if (rootA == rootB)
		{
			result = i + 1;
			break;
		}

		union_node(nodes, rootA, rootB);
	}

	cout << result << endl;
	return 0;
}