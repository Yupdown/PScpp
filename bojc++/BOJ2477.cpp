#include <iostream>

using namespace std;

int main()
{
	int k, table[6][2];
	cin >> k;

	for (int i = 0; i < 6; ++i)
		cin >> table[i][0] >> table[i][1];

	for (int i = 0; i < 6; ++i)
	{
		if (table[(i + 1) % 6][0] != table[(i + 3) % 6][0] && table[(i + 2) % 6][0] == table[(i + 4) % 6][0])
		{
			cout << (table[i][1] * table[(i + 1) % 6][1] - table[(i + 3) % 6][1] * table[(i + 4) % 6][1]) * k << endl;
			break;
		}
	}

	return 0;
}