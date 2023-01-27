#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		pq.push(v);
	}

	long long s = 0;
	while (pq.size() > 1)
	{
		int a =		pq.top();	pq.pop();
		int v = a +	pq.top();	pq.pop();
		s += v;
		pq.push(v);
	}

	cout << s << "\n";
}