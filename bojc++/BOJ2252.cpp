#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int indegree[32000] = { 0 };
	vector<int> nextNodes[32000];
	queue<int> indexQueue;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		indegree[b - 1] += 1;
		nextNodes[a - 1].push_back(b - 1);
	}

	for (int i = 0; i < n; i++)
	{
		if (!(indegree[i] > 0))
			indexQueue.push(i);
	}

	while (!indexQueue.empty())
	{
		int index = indexQueue.front();
		indexQueue.pop();

		for (int i = 0; i < nextNodes[index].size(); i++)
		{
			int next = nextNodes[index][i];

			if (--indegree[next] <= 0)
				indexQueue.push(next);
		}

		cout << index + 1 << ' ';
	}

	cout << endl;
	return 0;
}