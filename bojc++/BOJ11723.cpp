#include <iostream>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int m, bitmask = 0;
	cin >> m;

	while (m-- > 0)
	{
		string command;
		cin >> command;

		int x;
		if (command == "add")
		{
			cin >> x;
			bitmask |= 1 << (x - 1);
		}
		else if (command == "remove")
		{
			cin >> x;
			bitmask &= ~(1 << (x - 1));
		}
		else if (command == "check")
		{
			cin >> x;
			cout << (bitmask >> (x - 1) & 1) << '\n';
		}
		else if (command == "toggle")
		{
			cin >> x;
			bitmask ^= 1 << (x - 1);
		}
		else if (command == "all")
			bitmask = -1;
		else if (command == "empty")
			bitmask = 0;
	}

	return 0;
}