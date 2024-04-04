#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int a, b;
		scanf("%d:%d", &a, &b);
		printf("%02d:%02d %s\n", (a + 11) % 12 + 1, b, a >= 12 ? "PM" : "AM");
	}
}