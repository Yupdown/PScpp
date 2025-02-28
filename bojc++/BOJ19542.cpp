#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> edge[100000];
int level[100000];

int create_level(int node, int last)
{
	int result = 0;
	for (int i = 0; i < edge[node].size(); ++i)
	{
		if (edge[node][i] == last)
			continue;

		result = max(result, create_level(edge[node][i], node) + 1);
	}

	return level[node] = result != 0 ? result : 0;
}

int get_result(int node, int last, int d)
{
	if (level[node] < d)
		return last < 0 ? 1 : 0;

	int result = 0;
	for (int i = 0; i < edge[node].size(); ++i)
	{
		if (edge[node][i] == last)
			continue;

		result += get_result(edge[node][i], node, d);
	}

	return result + 1;
}

int main()
{
	int n, s, d;
	cin >> n >> s >> d;

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;

		edge[a - 1].push_back(b - 1);
		edge[b - 1].push_back(a - 1);
	}

	create_level(s - 1, -1);
	cout << (get_result(s - 1, -1, d) - 1) * 2 << endl;
	return 0;
}