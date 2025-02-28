#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] += nodes[node1];
	nodes[node1] = node0;
}

int get_index(map<string, int>* directory, string key, int* c)
{
	auto iter = directory->find(key);

	if (iter != directory->end())
		return iter->second;

	directory->insert(make_pair(key, *c));
	return (*c)++;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int nodes[200000];
	map<string, int> directory;

	int t;
	cin >> t;

	while (t-- > 0)
	{
		memset(nodes, -1, sizeof(nodes));
		directory.clear();

		int n, c = 0;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			string sp, sq;
			cin >> sp >> sq;

			int p = get_index(&directory, sp, &c);
			int q = get_index(&directory, sq, &c);

			int pp = find_node(nodes, p);
			int pq = find_node(nodes, q);

			cout << -(pp != pq ? nodes[pp] + nodes[pq] : nodes[pp]) << '\n';

			if (pp != pq)
				union_node(nodes, pp, pq);
		}
	}

	return 0;
}