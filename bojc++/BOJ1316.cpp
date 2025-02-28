#include <iostream>
#include <map>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, c = 0;
	char str[128];
	cin >> n;

	while (n-- > 0)
	{
		cin >> str;

		int field = 0;
		char* ptr = str;

		while (*ptr != 0)
		{
			int bit = 1 << (*ptr - 'a');
			if (ptr != str && *(ptr - 1) != *ptr && bit & field)
				break;
			field |= bit;
			ptr++;
		}

		if (*ptr == 0)
			c++;
	}

	cout << c << endl;
	return 0;
}