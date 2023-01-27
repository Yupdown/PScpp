#include <bits/stdc++.h>

using namespace std;

int flood[100001];

int main()
{
	int n, k;
	cin >> n >> k;

	cout << [](int n, int k)
	{
		int t = 0;
		queue<int> q;

		q.push(n);
		flood[n] = 1;

		while (!q.empty()) {
			int c = q.size();
			while (c-- > 0) {
				int x = q.front();
				q.pop();
				q.push(x);
				for (x *= 2; x <= 100000 && !flood[x]; x *= 2) {
					q.push(x);
					flood[x] = 1;
				}
			}

			c = q.size();
			while (c-- > 0) {
				int x = q.front();
				q.pop();
				if (x == k)
					return t;
				if (x + 1 <= 100000 && !flood[x + 1]) {
					q.push(x + 1);
					flood[x + 1] = 1;
				}
				if (x - 1 >= 0 && !flood[x - 1]) {
					q.push(x - 1);
					flood[x - 1] = 1;
				}
			}
			++t;
		}
		return -1;
	}(n, k);
}