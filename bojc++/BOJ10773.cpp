#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int k, r = 0;
	cin >> k;

	stack<int> container;

	while (k-- > 0)
	{
		int parameter;
		cin >> parameter;

		if (parameter > 0)
			container.push(parameter);
		else
			container.pop();
	}

	while (container.size() > 0)
	{
		r += container.top();
		container.pop();
	}

	cout << r << endl;
	return 0;
}