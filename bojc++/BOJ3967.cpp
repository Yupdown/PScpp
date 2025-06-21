#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char temp[][10] =
{
	"....A....",
	".B.C.D.E.",
	"..F...G..",
	".H.I.J.K.",
	"....L...."
};

char table[12];
bool memo[128];

bool verdict(int i, int j, int k, int l)
{
	if (table[i] == 'x' || table[j] == 'x' || table[k] == 'x' || table[l] == 'x')
		return true;
	return !(282 - table[i] - table[j] - table[k] - table[l]);
}

bool verdict()
{
	return verdict(0, 2, 5, 7) && verdict(7, 8, 9, 10) && verdict(10, 6, 3, 0) && verdict(1, 5, 8, 11) && verdict(11, 9, 6, 4) && verdict(4, 3, 2, 1);
}

bool solution(int i)
{
	if (!verdict())
		return false;
	if (i >= 12)
		return true;
	if (table[i] != 'x')
		return solution(i + 1);
	for (char c = 'A'; c <= 'L'; ++c)
	{
		if (memo[c])
			continue;
		memo[c] = true;
		table[i] = c;
		if (solution(i + 1))
			return true;
		memo[c] = false;
		table[i] = 'x';
	}
	return false;
}

int main()
{
	FASTIO();

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			char x;
			cin >> x;
			if (temp[i][j] == '.')
				continue;
			table[temp[i][j] - 'A'] = x;
			memo[x] = true;
		}

	}
	solution(0);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (temp[i][j] == '.')
				cout << '.';
			else
				cout << table[temp[i][j] - 'A'];
		}
		cout << "\n";
	}
}