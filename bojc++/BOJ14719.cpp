#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
	int h, w, s = 0;
	cin >> h >> w;

	int map[500];
	for (int i = 0; i < w; i++)
		cin >> map[i];

	stack<int> backtracking;

	for (int i = 1; i < w; i++)
	{
		if (map[i - 1] < map[i])
		{
			int low = map[i - 1];
			while (!backtracking.empty())
			{
				int last = backtracking.top();

				s += (i - (last + 1)) * (min(map[i], map[last]) - low);
				low = map[last];

				if (map[i] < map[last])
					break;

				backtracking.pop();
			}
		}
		else
			backtracking.push(i - 1);
	}

	cout << s << endl;
	return 0;
}