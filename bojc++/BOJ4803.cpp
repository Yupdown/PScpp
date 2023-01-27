#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> next_nodes[500];
bool flood_map[500];

int Function(int current_node, int last_node)
{
	if (flood_map[current_node])
		return 0;
	flood_map[current_node] = 1;

	int result = 1;
	for (int next_node : next_nodes[current_node])
	{
		if (next_node == last_node)
			continue;
		result &= Function(next_node, current_node);
	}

	return result;
}

int main()
{
	FASTIO();

	int c = 0;
	while (true)
	{
		int n, m;
		cin >> n >> m;

		if (!n && !m)
			break;

		for (int i = 0; i < n; ++i)
		{
			next_nodes[i].clear();
			flood_map[i] = 0;
		}

		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			next_nodes[a - 1].push_back(b - 1);
			next_nodes[b - 1].push_back(a - 1);
		}

		int t = 0;

		for (int i = 0; i < n; ++i)
		{
			if (flood_map[i])
				continue;
			t += Function(i, -1);
		}

		cout << "Case " << ++c << ": ";
		switch (t)
		{
		case 0:
			cout << "No trees.";
			break;
		case 1:
			cout << "There is one tree.";
			break;
		default:
			cout << "A forest of " << t << " trees.";
			break;
		}
		cout << "\n";
	}
	
}