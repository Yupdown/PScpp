#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> queue_back;
	priority_queue<int, vector<int>, less<int>> queue_front;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;

		if (queue_front.size() > 0 && v < queue_front.top())
		{
			queue_front.push(v);
			int fv = queue_front.top();
			queue_front.pop();
			queue_back.push(fv);
		}
		else
			queue_back.push(v);

		if (i > 0 && !(i % 2))
		{
			queue_front.push(queue_back.top());
			queue_back.pop();
		}

		cout << queue_back.top() << '\n';
	}

	return 0;
}