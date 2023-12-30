#include <bits/stdc++.h>

using namespace std;

char table[4];

int main()
{
	int n;
	cin >> n;

	while (n-- > 0)
	{
		for (int i = 0; i < 3; ++i)
		{
			cin >> table;
			bool flag = false;
			int sum = 0;
			for (int j = 0; j < 3; ++j)
			{
				if (table[j] == '?')
					flag = true;
				else
					sum += table[j];
			}

			if (flag)
			{
				cout << (char)('A' + 'B' + 'C' - sum) << '\n';
				continue;
			}
		}
	}
}
