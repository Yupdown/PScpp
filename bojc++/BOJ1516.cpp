#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int construction[500];
int indegree[500];
int memoization[500];
vector<int> condition[500];

void get_result(int current, int value)
{
	memoization[current] = max(memoization[current], value + construction[current]);

	if (--indegree[current] > 0)
		return;

	for (int next : condition[current])
		get_result(next, memoization[current]);
}

int main()
{
	FASTIO();

	int n, v;
	cin >> n;

	vector<int> roots;

	for (int i = 0; i < n; ++i)
	{
		cin >> construction[i];

		while (cin >> v) {
			if (v < 0)
				break;
			condition[v - 1].push_back(i);
			++indegree[i];
		}

		if (indegree[i] <= 0)
			roots.push_back(i);
	}

	for (int root : roots)
		get_result(root, 0);

	for (int i = 0; i < n; ++i)
		cout << memoization[i] << '\n';

	return 0;
}