#include <bits/stdc++.h>

using namespace std;
int s[10000];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	if (n > 1)
	{
		sort(s, s + n);
		for (int i = 0; i < n - 1; ++i)
			s[i] = s[i + 1] - s[i];
		sort(s, s + n - 1);
		cout << accumulate(s, s + n - k, 0);
	}
	else
		cout << 0;
}