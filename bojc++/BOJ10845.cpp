#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> q;

	while (n-- > 0)
	{
		string command;
		cin >> command;

		if (!command.compare("push"))
		{
			int parameter;
			cin >> parameter;

			q.push(parameter);
		}
		else if (!command.compare("pop"))
		{
			if (q.size() > 0)
			{
				cout << q.front();
				q.pop();
			}
			else
				cout << -1;
			cout << endl;
		}
		else if (!command.compare("size"))
		{
			cout << q.size();
			cout << endl;
		}
		else if (!command.compare("empty"))
		{
			cout << (int)q.empty();
			cout << endl;
		}
		else if (!command.compare("front"))
		{
			if (q.size() > 0)
				cout << q.front();
			else
				cout << -1;
			cout << endl;
		}
		else if (!command.compare("back"))
		{
			if (q.size() > 0)
				cout << q.back();
			else
				cout << -1;
			cout << endl;
		}
	}

	return 0;
}