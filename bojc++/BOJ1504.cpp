#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<pair<int, int>> edge[800];

int dist(int v, int from, int to)
{
	int result[800]{};
	priority_queue<pair<int, int>> search_queue;

	for (int i = 0; i < v; ++i)
		result[i] = i != from ? INT32_MAX : 0;
	search_queue.push(make_pair(0, from));

	while (!search_queue.empty()) {
		int current_node = search_queue.top().second;
		search_queue.pop();

		for (const pair<int, int>& next_node : edge[current_node]) {
			int value = result[current_node] + next_node.second;
			if (value < result[next_node.first]) {
				result[next_node.first] = value;
				search_queue.push(make_pair(-value, next_node.first));
			}
		}
	}

	return result[to];
}

int main()
{
	FASTIO();

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edge[u - 1].push_back(make_pair(v - 1, w));
		edge[v - 1].push_back(make_pair(u - 1, w));
	}

	int v1, v2;
	cin >> v1 >> v2;

	int table[] = {
		dist(v, 0, v1 - 1),
		dist(v, 0, v2 - 1),
		dist(v, v1 - 1, v2 - 1),
		dist(v, v1 - 1, v - 1),
		dist(v, v2 - 1, v1 - 1),
		dist(v, v2 - 1, v - 1)
	};

	if (count(begin(table), end(table), INT32_MAX) > 0)
		cout << "-1";
	else
		cout << min(table[0] + table[2] + table[5], table[1] + table[4] + table[3]);
}