#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	string s;
	int t;
	cin >> t;

	while (t-- > 0)
	{
		cin >> s;
		cout << (count(s.begin(), s.end(), 'A') > 2 ? 'A' : 'B') << '\n';
	}
}