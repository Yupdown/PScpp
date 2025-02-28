#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> s;

	while (n-- > 0)
	{
		string command;
		cin >> command;

		if (!command.compare("push"))
		{
			int parameter;
			cin >> parameter;

			s.push(parameter);
		}
		else if (!command.compare("pop"))
		{
			if (s.size() > 0)
			{
				cout << s.top();
				s.pop();
			}
			else
				cout << -1;
			cout << endl;
		}
		else if (!command.compare("size"))
		{
			cout << s.size();
			cout << endl;
		}
		else if (!command.compare("empty"))
		{
			cout << (int)s.empty();
			cout << endl;
		}
		else if (!command.compare("top"))
		{
			if (s.size() > 0)
				cout << s.top();
			else
				cout << -1;
			cout << endl;
		}
	}

	return 0;
}