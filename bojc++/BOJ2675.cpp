#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int c;
		char string[32];
		cin >> c >> string;

		for (int j = 0; string[j] != 0; j++)
		{
			for (int k = 0; k < c; k++)
				cout << string[j];
		}
		cout << endl;
	}

	return 0;
}