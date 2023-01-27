#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int s[200000];
int t[200000];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> s[i] >> t[i];

	sort(s, s + n);
	sort(t, t + n);

	int maxv = 1;
	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j < n && s[j] < t[i])
			++j;
		maxv = max(maxv, j - i);
	}

	cout << maxv << endl;
}