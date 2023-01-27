#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, l;
	cin >> n >> l;

	int x = -1;
	do
	{
		long long nume = static_cast<long long>(n) * 2 - l * l - l;
		long long deno = l * 2;

		if (!(nume % deno))
			x = (nume / deno) + 1;
		else
			++l;

		if (nume <= 0)
			break;

	} while (x < 0 && !(l > 100));

	if (x < 0)
		cout << -1 << '\n';
	else
	{
		do
			cout << x++ << ' ';
		while (--l > 0);
		cout << '\n';
	}
}