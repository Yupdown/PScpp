#include <iostream>

using namespace std;

int main()
{
	char str[50][51];

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> str[i];

	for (int i = 0; str[0][i] != 0; ++i)
	{
		bool flag = false;
		for (int j = 1; j < n; ++j)
		{
			if (str[0][i] != str[j][i])
			{
				flag = true;
				break;
			}
		}
		str[0][i] = flag ? '?' : str[0][i];
	}

	cout << str[0] << endl;
	return 0;
}