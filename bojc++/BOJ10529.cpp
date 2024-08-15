#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

string s[10];
vector<char> table;

int solution(int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (s[i].front() == table[0])
			return 0;
	}

	char table_inv[26];
	for (int i = 0; i < 10; ++i)
		table_inv[table[i] - 'A'] = i;

	long long hom[10];
	for (int i = 0; i < n; ++i)
	{
		hom[i] = 0;
		for (char c : s[i])
			hom[i] = hom[i] * 10 + table_inv[c - 'A'];
	}

	return accumulate(hom, hom + n - 1, 0ll) == hom[n - 1];
}

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	for (int i = 0; i < n; ++i)
	{
		for (char c : s[i])
			table.push_back(c);
	}

	sort(table.begin(), table.end());
	table.erase(unique(table.begin(), table.end()), table.end());
	table.resize(10, 0);
	sort(table.begin(), table.end());

	int ret = 0;
	do
		ret += solution(n);
	while (next_permutation(table.begin(), table.end()));

	cout << ret;
}