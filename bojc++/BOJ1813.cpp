#include <bits/stdc++.h>

using namespace std;
int cnt[51];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		cnt[v]++;
	}
	auto it = find_if(rbegin(cnt), rend(cnt), [](int& c) { return c == distance(cnt, &c); });
	cout << (it == rend(cnt) ? -1 : *it);
}