#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using ll = long long;

int main()
{
	ll n;
	string s;
	cin >> n >> s;
	int hcnt = 0, ocnt = 0;
	for (char c : s)
	{
		(c == 'H' ? hcnt : ocnt)++;
		if (ocnt > hcnt)
		{
			cout << "mix";
			return 0;
		}
	}
	hcnt = 0, ocnt = 0;
	reverse(s.begin(), s.end());
	for (char c : s)
	{
		(c == 'H' ? hcnt : ocnt)++;
		if (ocnt > hcnt)
		{
			cout << "mix";
			return 0;
		}
	}
	cout << (ocnt * 2 == hcnt ? "pure" : "mix");
}