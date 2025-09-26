#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int height[200000];
vector<int> edge[200000];

int solution(int node, int node_prev)
{
	int height_max = height[node];
	bool flag = false;
	for (int node_next : edge[node])
	{
		if (node_next == node_prev)
			continue;
		int height_next = solution(node_next, node);
		if (height_next < height_max)
			continue;
		height_max = height[node] + (height_next - height[node]) / 2;
		flag = true;
	}
	if (node_prev < 0)
		return flag;
	return height_max;
}

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> height[i];
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		edge[a - 1].emplace_back(b - 1);
		edge[b - 1].emplace_back(a - 1);
	}
	cout << solution(k - 1, -1);
}