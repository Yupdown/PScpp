#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char table[10000][501];

int solution(int r, int c, int row, int col)
{
	if (table[row][col] == 'x')
		return 0;
	table[row][col] = 'x';
	if (col == c - 1)
		return 1;
	if (row - 1 >= 0 && solution(r, c, row - 1, col + 1))
		return 1;
	if (solution(r, c, row, col + 1))
		return 1;
	if (row + 1 < r && solution(r, c, row + 1, col + 1))
		return 1;
	return 0;
}

int main()
{
	FASTIO();
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		cin >> table[i];
	int ret = 0;
	for (int i = 0; i < r; ++i)
		ret += solution(r, c, i, 0);
	cout << ret;
}