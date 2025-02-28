#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>* nextIndexes, bool* visited, int start)
{
	vector<int> nextIndex = nextIndexes[start];

	visited[start] = true;
	for (int i = 0; i < nextIndex.size(); i++)
	{
		if (!visited[nextIndex[i]])
			dfs(nextIndexes, visited, nextIndex[i]);
	}
}

int main()
{
	int n, m, c = 0;
	cin >> n >> m;

	vector<int>* nextIndexes = new vector<int>[n];
	bool* visited = new bool[n] { false };

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		nextIndexes[a - 1].push_back(b - 1);
		nextIndexes[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(nextIndexes, visited, i);
			c++;
		}
	}

	cout << c << endl;
	return 0;
}