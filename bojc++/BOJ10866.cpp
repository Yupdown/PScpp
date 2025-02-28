#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	deque<int> container;

	while (n-- > 0)
	{
		string command;
		cin >> command;

		if (!command.compare("push_front"))
		{
			int parameter;
			cin >> parameter;

			container.push_front(parameter);
		}
		if (!command.compare("push_back"))
		{
			int parameter;
			cin >> parameter;

			container.push_back(parameter);
		}
		else if (!command.compare("pop_front"))
		{
			if (container.size() > 0)
			{
				cout << container.front();
				container.pop_front();
			}
			else
				cout << -1;
			cout << endl;
		}
		else if (!command.compare("pop_back"))
		{
			if (container.size() > 0)
			{
				cout << container.back();
				container.pop_back();
			}
			else
				cout << -1;
			cout << endl;
		}
		else if (!command.compare("size"))
		{
			cout << container.size();
			cout << endl;
		}
		else if (!command.compare("empty"))
		{
			cout << (int)container.empty();
			cout << endl;
		}
		else if (!command.compare("front"))
		{
			if (container.size() > 0)
				cout << container.front();
			else
				cout << -1;
			cout << endl;
		}
		else if (!command.compare("back"))
		{
			if (container.size() > 0)
				cout << container.back();
			else
				cout << -1;
			cout << endl;
		}
	}

	return 0;
}