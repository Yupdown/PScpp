#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int board[10][10];
vector<pair<int, int>> caseCoords;

bool check_occupied(int n, int x, int y)
{
	int nx = x + 1;
	int ny = y - 1;

	while (nx < n && ny >= 0)
	{
		if (board[nx++][ny--] != 0)
			return true;
	}

	nx = x - 1;
	ny = y - 1;

	while (nx >= 0 && ny >= 0)
	{
		if (board[nx--][ny--] != 0)
			return true;
	}

	return false;
}

int get_result(int n, int m, int c, int t)
{
	int result = c;

	for (int i = m; i < caseCoords.size(); i++)
	{
		int x = caseCoords[i].first;
		int y = caseCoords[i].second;

		if (((x + y) % 2) ^ t)
			continue;

		if (board[x][y] == 0)
		{
			if (!check_occupied(n, x, y))
			{
				board[x][y] = 1;
				result = max(result, get_result(n, i + 1, c + 1, t));
				board[x][y] = 0;
			}
		}
	}

	return result;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n * n; i++)
	{
		int value;
		cin >> value;

		int x = i % n;
		int y = i / n;

		if (value > 0)
			caseCoords.push_back({ x, y });
	}

	cout << get_result(n, 0, 0, 0) + get_result(n, 0, 0, 1) << endl;
	return 0;
}