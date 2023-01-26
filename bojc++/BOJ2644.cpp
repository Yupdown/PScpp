#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[101];

int main()
{
	FASTIO();

	int n, m, a, b;
	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		table[y] = x;
	}

	stack<int> sa, sb;
	for (int i = a; i != 0; i = table[i])
		sa.push(i);
	for (int i = b; i != 0; i = table[i])
		sb.push(i);

	int r;
	if (sa.top() == sb.top()) {
		while (!sa.empty() && !sb.empty() && sa.top() == sb.top()) {
			sa.pop();
			sb.pop();
		}
		r = sa.size() + sb.size();
	}
	else
		r = -1;
	cout << r;
}