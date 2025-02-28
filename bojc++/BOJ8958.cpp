#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char string[128];
		cin >> string;

		int score = 0;
		for (int j = 0, k = 0; string[j] != 0; j++)
		{
			if (string[j] == 'O')
				score += ++k;
			else
				k = 0;
		}

		cout << score << endl;
	}
}