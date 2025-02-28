#include <iostream>
#include <vector>
#include <cmath>

#define SIZEOF_CACHE 1000000

using namespace std;

vector<int> edge[SIZEOF_CACHE];
int dynamic[SIZEOF_CACHE][2];

void build_dynamic(int index, int last_index)
{
	dynamic[index][1] = 1;
	for (int i = 0; i < edge[index].size(); ++i)
	{
		int next_index = edge[index][i];
		if (next_index == last_index)
			continue;

		build_dynamic(next_index, index);

		dynamic[index][0] += dynamic[next_index][1];
		dynamic[index][1] += min(dynamic[next_index][0], dynamic[next_index][1]);
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;

		edge[u - 1].push_back(v - 1);
		edge[v - 1].push_back(u - 1);
	}

	build_dynamic(0, -1);
	cout << min(dynamic[0][0], dynamic[0][1]) << endl;

	return 0;
}