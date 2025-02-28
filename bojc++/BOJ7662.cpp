#include <iostream>
#include <set>

using namespace std;

int main()
{
	multiset<int> container;

	int t;
	cin >> t;
	while (t-- > 0)
	{
		int k;
		cin >> k;

		while (k-- > 0)
		{
			char command;
			int parameter;
			cin >> command >> parameter;

			switch (command)
			{
			case 'I':
				container.insert(parameter);
				break;

			case 'D':
				if (container.empty())
					break;
				else if (parameter > 0)
					container.erase(--container.end());
				else
					container.erase(container.begin());
				break;

			default:
				break;
			}
		}

		if (container.empty())
			cout << "EMPTY" << endl;
		else
			cout << *(--container.end()) << ' ' << *(container.begin()) << endl;
		container.clear();
	}

	return 0;
}