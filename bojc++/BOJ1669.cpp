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
		flood[n] = -1;

		while (!q.empty()) {
			int c = q.size();
			while (c-- > 0) {
				int x = q.front();
				q.pop();

				if (x == k)
					return t;
				if (x * 2 <= 100000 && !flood[x * 2]) {
					q.push(x * 2);
					flood[x * 2] = x;
				}
				if (x + 1 <= 100000 && !flood[x + 1]) {
					q.push(x + 1);
					flood[x + 1] = x;
				}
				if (x - 1 >= 0 && !flood[x - 1]) {
					q.push(x - 1);
					flood[x - 1] = x;
				}
			}	
			++t;
		}
		return -1;
	}(n, k);

	int back_track = k;
	while (back_track > 0) {
		cout << back_track << ' ';
		back_track = flood[back_track];
	}
}