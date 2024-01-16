#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[300000];
int depth_count[300002] = { 1 };
queue<int> nodes[300001];

int inorder(int depth, int order)
{
	if (depth_count[depth] <= 0)
		return order;
	--depth_count[depth];
	order = inorder(depth + 1, order);
	nodes[depth].push(order++);
	return inorder(depth + 1, order);
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
		cin >> table[i];

	bool flag = true;
	for (int i = 0; i < n - 1; ++i)
	{
		int depth = table[i];
		depth_count[depth]++;
		flag &= depth_count[depth] <= 1 << min(depth, 20) && depth_count[depth - 1] << 1 >= depth_count[depth];
	}

	if (!flag)
		cout << -1;
	else
	{
		inorder(0, 1);
		for (int i = 0; i < n; ++i)
		{
			int depth = i > 0 ? table[i - 1] : 0;
			cout << nodes[depth].front() << ' ';
			nodes[depth].pop();
		}
	}
}