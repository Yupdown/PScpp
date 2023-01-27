#include <bits/stdc++.h>
#define SIZEOF_ARRAY(a) (sizeof(a) / sizeof(*(a)))

using namespace std;

int flood[100001];

int main()
{
	queue<int> q;
	int n, k;
	cin >> n >> k;

	q.push(n);
	flood[n] = 1;

	int c = 0;
	bool flag = n != k;
	while (flag) {
		int l = q.size();
		while (l-- > 0) {
			int x = q.front();
			q.pop();
			int next[]{ x - 1, x + 1, x * 2 };
			for (int i = 0; i < SIZEOF_ARRAY(next); ++i) {
				if (next[i] < 0 || next[i] > 100000)
					continue;
				if (next[i] == k)
					flag = false;
				if (!flood[next[i]])
					q.push(next[i]);
				flood[next[i]] += flood[x];
			}
		}
		++c;
	}

	cout << c << "\n" << flood[k];
}