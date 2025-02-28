#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

set<int> result;
vector<int> graph[10000];
int node_count, node_span[10000];

int df_search(int current, bool root)
{
	int span = node_span[current] = ++node_count;
	int child_count = 0;

	for (int i = 0; i < graph[current].size(); ++i)
	{
		int next = graph[current][i];

		if (node_span[next] > 0)
			span = min(span, node_span[next]);
		else
		{
			++child_count;
			int child_span = df_search(next, false);
			if (!root && child_span >= node_span[current])
				result.insert(current);
			span = min(span, child_span);
		}
	}
	if (root && child_count > 1)
		result.insert(current);

	return span;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;

		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < v; ++i)
	{
		if (!(node_span[i] > 0))
			df_search(i, true);
	}

	cout << result.size() << endl;
	for (auto iter = result.begin(); iter != result.end(); iter++)
		cout << *iter + 1 << ' ';
	cout << endl;

	return 0;
}