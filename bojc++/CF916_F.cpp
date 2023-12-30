#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> edge[100000];
set<int> depth[100000];

void solution(int node, int d)
{
	depth[d].insert(node);
	for (auto e : edge[node])
		solution(e, d + 1);
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i)
		{
			edge[i].clear();
			depth[i].clear();
		}

		for (int i = 1; i < n; ++i)
		{
			int v;
			cin >> v;
			edge[v - 1].push_back(i);
		}
		solution(0, 0);
		
		int r = 0;
		for (int i = n - 1; i >= 0; --i)
		{

		}
	}
}