#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	pair<int, int> mv[300000];
	int c[300000];

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> mv[i].first >> mv[i].second;

	for (int i = 0; i < k; i++)
		cin >> c[i];

	sort(mv, mv + n, [](pair<int, int> a, pair<int, int> b) -> bool { return a.first < b.first; });
	sort(c, c + k);

	priority_queue<int> pq;
	long long result = 0LL;

	for (int i = 0, j = 0; i < k; i++)
	{
		while (mv[j].first <= c[i] && j < n)
			pq.push(mv[j++].second);

		if (!pq.empty())
		{
			result += (long long)pq.top();
			pq.pop();
		}
	}

	cout << result << endl;
	return 0;
}