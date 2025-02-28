#include <iostream>
#include <queue>

using namespace std;

int main()
{
	char board[81 + 1];
	for (int i = 0; i < 9; i++)
		cin >> board + i * 9;

	queue<char> cases[81];

	for (int i = 0; i < 81; i++)
	{
		if (board[i] != '0')
			continue;

		int mask = 1;
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

				mask |= 1 << (value - '0');
			}
		}

		if (mask == 1023)
		{
			while (cases[i].size() < 2)
			{
				if (cases[i].size() > 0)
					cases[i].pop();
				i--;
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
	{
		cout << (cases[i].empty() ? board[i] : cases[i].front());
		if (i % 9 == 8)
			cout << endl;
	}

	return 0;
}