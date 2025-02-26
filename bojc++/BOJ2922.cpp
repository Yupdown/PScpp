#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char table[128];

bool is_vowel(char c)
{
	switch (c)
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		return true;
	}
	return false;
}

long long solution(int n, int i, int v, int c, int l)
{
	if (v >= 3 || c >= 3)
		return 0;
	if (i == n)
		return l;
	if (table[i] == '_')
		return solution(n, i + 1, v + 1, 0, l) * 5 + solution(n, i + 1, 0, c + 1, l) * 20 + solution(n, i + 1, 0, c + 1, 1);
	else
	{
		bool vowel = is_vowel(table[i]);
		return solution(n, i + 1, (v + 1) * vowel, (c + 1) * !vowel, l | table[i] == 'L');
	}
}

int main()
{
	FASTIO();
	cin >> table;
	cout << solution(strlen(table), 0, 0, 0, 0);
}