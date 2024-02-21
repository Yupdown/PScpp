#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define TARGET (edges[target_parent][target_index])

using namespace std;

vector<int> edges[2000];
int parents[2000];
bool toggle[2000] = { true };
int target_parent = 0;
int target_index = 0;

int main()
{
	FASTIO();

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;

		for (int j = 0; j < c; ++j)
		{
			int v;
			cin >> v;
			edges[i].push_back(v - 1);
			parents[v - 1] = i;
		}
	}

	char buffer[16];
	int k;

	stack<int> s;

	for (int i = 0; i < q; ++i)
	{
		cin >> buffer;

		switch (buffer[0])
		{
		case 't':
			toggle[TARGET] = !toggle[TARGET];
			break;
		case 'm':
			cin >> k;
			while (k > 0)
			{
				if (toggle[TARGET] && edges[TARGET].size() > 0)
				{
					s.push(target_index);
					target_parent = TARGET;
					target_index = 0;
				}
				else
				{
					int initial_parent = target_parent;
					int initial_index = target_index;
					stack<int> tmp = s;

					while (target_parent > 0 && target_index >= edges[target_parent].size() - 1)
					{
						target_parent = parents[target_parent];
						target_index = s.top();
						s.pop();
					}
					if (target_index < edges[target_parent].size() - 1)
						++target_index;
					else
					{
						target_parent = initial_parent;
						target_index = initial_index;
						s = tmp;
					}
				}
				--k;
			}
			while (k < 0)
			{
				if (target_index > 0)
				{
					--target_index;
					while (toggle[TARGET] && edges[TARGET].size() > 0)
					{
						s.push(target_index);
						target_parent = TARGET;
						target_index = edges[target_parent].size() - 1;
					}
				}
				else if (target_parent > 0)
				{
					target_parent = parents[target_parent];
					target_index = s.top();
					s.pop();
				}
				++k;
			}
			cout << TARGET + 1 << '\n';
			break;
		}
	}
}