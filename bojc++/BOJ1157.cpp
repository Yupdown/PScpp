#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[26];

int main()
{
	FASTIO();

	string s;
	cin >> s;
	for_each(s.begin(), s.end(), [](char c) { memo[toupper(c) - 'A']++; });
	auto p1 = max_element(cbegin(memo), cend(memo));
	auto p2 = max_element(crbegin(memo), crend(memo)).base() - 1;
	cout << (p1 != p2 ? '?' : static_cast<char>('A' + p1 - memo));
}