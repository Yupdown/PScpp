#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char c_buffer[8192];
char l_buffer[8192];

int main()
{
	FASTIO();

	int n;
	cin >> n;

	memset(c_buffer, ' ', sizeof(c_buffer));
	memset(l_buffer, ' ', sizeof(l_buffer));
	l_buffer[n - 1] = '*';
	l_buffer[n * 2 - 1] = 0;
	cout << l_buffer << "\n";

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < n + i; ++j)
		{
			bool flag = false;
			bool condition[3];
			for (int k = 0; k < 3; ++k)
				condition[k] = j + k > 0 ? l_buffer[j + k - 1] == '*' : false;
			switch (i % 3)
			{
			case 0:
				flag = condition[0] != condition[2];
				flag &= !condition[1];
				break;
			case 1:
				flag = condition[0] || condition[2];
				break;
			case 2:
				flag = condition[0] || condition[1] || condition[2];
				break;
			}
			c_buffer[j] = flag ? '*' : ' ';
		}
		c_buffer[n * 2 - 1] = 0;
		cout << c_buffer << "\n";
		memcpy(l_buffer, c_buffer, sizeof(l_buffer));
	}
}