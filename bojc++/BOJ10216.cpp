#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

inline int find_node(int* nodes, int node)
{
	return nodes[node] < 0 ? node : (nodes[node] = find_node(nodes, nodes[node]));
}

inline void union_node(int* nodes, int node0, int node1)
{
	nodes[node0] += nodes[node1];
	nodes[node1] = node0;
}

int main()
{
	FASTIO();

	int t, nodes[3000];
	cin >> t;

	while (t-- > 0)
	{
		int n, input[3000][3];

		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> input[i][0] >> input[i][1] >> input[i][2];
			nodes[i] = -1;
		}

		int result = n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				int pi = find_node(nodes, i);
				int pj = find_node(nodes, j);

				if (pi == pj)
					continue;

				int dx = input[i][0] - input[j][0];
				int dy = input[i][1] - input[j][1];
				int r = input[i][2] + input[j][2];

				if (dx * dx + dy * dy <= r * r)
				{
					union_node(nodes, pi, pj);
					--result;
				}
			}
		}

		cout << result << endl;
	}

	return 0;
}