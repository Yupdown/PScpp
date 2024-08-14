#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t--)
	{
		string a;
		cin >> a;
		if (a.size() < 3)
			cout << "NO";
		else if (a.substr(0, 2) != "10")
			cout << "NO";
		else
		{
			string s = a.substr(2);
			int i = 0;
			if (s.front() == '0')
				cout << "NO";
			else
			{
				for (char c : s)
				{
					i *= 10;
					i += c - '0';
				}
				cout << (i >= 2 ? "YES" : "NO");
			}
		}
		cout << '\n';
	}
}