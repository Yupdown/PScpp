#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int track[10000] = { 0 };
		queue<int> bfs;

		int a, b;
		cin >> a >> b;

		bfs.push(a);
		track[a] = -1;

		do
		{
			int value = bfs.front();
			bfs.pop();

			if (value == b)
				break;

			pair<char, int> next[4] =
			{
				{ 'D', value * 2 % 10000 },
				{ 'S', value > 0 ? value - 1 : 9999 },
				{ 'L', value / 1000 + value * 10 % 10000 },
				{ 'R', value / 10 + value * 1000 % 10000 }
			};

			for (int i = 0; i < 4; i++)
			{
				if (track[next[i].second] != 0)
					continue;

				bfs.push(next[i].second);
				track[next[i].second] = next[i].first * 10000 + value;
			}

		} while (!bfs.empty());

		stack<char> result;
		for (int i = b; track[i] != -1; i = track[i] % 10000)
			result.push((char)(track[i] / 10000));

		while (!result.empty())
		{
			cout << result.top();
			result.pop();
		}
		cout << endl;
	}

	return 0;
}