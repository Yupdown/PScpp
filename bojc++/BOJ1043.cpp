#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int trut[50];
int node[51];
vector<int> parties[50];

inline int find_node(int* nodes, int node)
{
	return nodes[node] <= 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] = 0;
	nodes[node1] = node0;
}

int main()
{
	FASTIO();

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
		cin >> trut[i];
	
	for (int i = 0; i < m; ++i)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			int v;
			cin >> v;
			parties[i].push_back(v);
			for (int l = 0; l < j; ++l)
			{
				int up = find_node(node, parties[i][j]);
				int vp = find_node(node, parties[i][l]);
				if (up != vp)
					union_node(node, up, vp);
			}
		}
	}

	int r = 0;
	for (int i = 0; i < m; ++i)
	{
		bool flag = true;
		for (int j = 0; j < parties[i].size() && flag; ++j)
		{
			for (int l = 0; l < k; ++l)
			{
				if (find_node(node, trut[l]) == find_node(node, parties[i][j]))
				{
					flag = false;
					break;
				}
			}
		}
		r += flag;
	}

	cout << r;
}