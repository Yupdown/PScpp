#include <iostream>
#include <queue>

using namespace std;

bool function(char board[81 + 1])
{
	queue<char> cases[81];

	for (int i = 0; i < 81; i++)
	{
		if (board[i] != '0')
			continue;

		int mask = 1;
		int masks[3] = { 0 };

		for (int j = 0; j < 9; j++)
		{
			int indexes[3];

			indexes[0] = (i / 9) * 9 + j;
			indexes[1] = (i % 9) + 9 * j;
			indexes[2] = (i % 9 / 3 * 3 + j % 3) + (9 * (i / 9 / 3 * 3 + j / 3));

			for (int k = 0; k < 3; k++)
			{
				if (indexes[k] == i)
					continue;

				char value = board[indexes[k]];

				if (value == '0' && !cases[indexes[k]].empty())
					value = cases[indexes[k]].front();

				int bit = 1 << (value - '0');
				if (masks[k] & bit && bit != 1)
					return false;
				masks[k] |= bit;
				mask |= bit;
			}
		}

		if (mask == 1023)
		{
			while (cases[i].size() < 2)
			{
				if (cases[i].size() > 0)
					cases[i].pop();
				if (--i < 0)
					return false;
			}
			cases[i].pop();
		}
		else
		{
			for (int j = 0; j < 9; j++)
			{
				if ((mask & (1 << (j + 1))) == 0)
					cases[i].push(j + 1 + '0');
			}
		}
	}

	for (int i = 0; i < 81; i++)
		board[i] = (cases[i].empty() ? board[i] : cases[i].front());
	return true;
}

int main()
{
	char board[81 + 1];
	int t;
	cin >> t;
	while (t-- > 0)
	{
		for (int i = 0; i < 9; i++)
			cin >> board + i * 9;

		if (function(board))
		{
			for (int i = 0; i < 81; i++)
			{
				cout << board[i];
				if (i % 9 == 8)
					cout << endl;
			}
		}
		else
			cout << "Could not complete this grid." << endl;
		cout << endl;
	}

	return 0;
}