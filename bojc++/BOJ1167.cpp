#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<pair<int, int>> elements[100000];
int value[100000];

int Function(int node_index, int last_index)
{
	int vmax[2]{};

	for (pair<int, int> element : elements[node_index])
	{
		if (element.first == last_index)
			continue;

		int v = Function(element.first, node_index) + element.second;

		if (v > vmax[0])
		{
			vmax[1] = vmax[0];
			vmax[0] = v;
		}
		else if (v > vmax[1])
			vmax[1] = v;
	}

	value[node_index] = vmax[0] + vmax[1];
	return vmax[0];
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int p, e, v;
		cin >> p;

		while (true)
		{
			cin >> e;
			if (e < 0)
				break;
			cin >> v;
			elements[p - 1].push_back(make_pair(e - 1, v));
		}
	}

	Function(0, -1);

	int result = value[0];
	for (int i = 1; i < n; ++i)
		result = max(result, value[i]);

	cout << result << endl;
}