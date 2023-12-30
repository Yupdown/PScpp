#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

struct pair_cmp
{
	bool operator()(pair<int, int> lhs, pair<int, int> rhs)
	{
		if (lhs.first == rhs.first)
			return lhs.second > rhs.second;
		return lhs.first > rhs.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, pair_cmp> pq;

int main()
{
	FASTIO();

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		pq.push(make_pair(v, i));

		while (pq.top().second - 1 < i - l)
			pq.pop();
		cout << pq.top().first << " ";
	}
}