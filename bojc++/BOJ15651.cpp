#include <iostream>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

void Function(char* buffer, int n, int m, int i)
{
	if (i < m)
	{
		for (int k = 0; k < n; ++k)
		{
			buffer[i * 2] = k + 49;
			Function(buffer, n, m, i + 1);
		}
	}
	else
		cout << buffer;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;

	char buffer[15]{};

	for (int i = 0; i < m * 2 - 1; ++i)
		buffer[i] = 32;
	buffer[m * 2 - 1] = 10;

	Function(buffer, n, m, 0);
}