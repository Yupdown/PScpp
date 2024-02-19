#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[26];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char c;
		cin >> c;
		table[c - 'A']++;
	}

	char c;
	cin >> c;
	cout << table[c - 'A'];
}