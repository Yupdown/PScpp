#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	long long r = 0;
	stack<pair<int, int>> height_stack;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int b;
		cin >> b;

		while (!height_stack.empty())
		{
			if (height_stack.top().first >= b)
				break;

			r += height_stack.top().second;
			height_stack.pop();
		}

		if (height_stack.empty())
			height_stack.push({ b, 1 });
		else
		{
			if (height_stack.top().first == b)
			{
				pair<int, int> temp = height_stack.top();
				height_stack.pop();

				r += temp.second;

				if (!height_stack.empty())
					r += 1;

				temp.second += 1;
				height_stack.push(temp);
			}
			else
			{
				height_stack.push({ b, 1 });
				r += 1;
			}
		}
	}

	cout << r << endl;
	return 0;
}