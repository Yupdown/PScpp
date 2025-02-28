#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int array[1000000] = { 0 };

	int n;
	cin >> n;

	queue<int> indexQueue;
	indexQueue.push(0);

	while (indexQueue.size() > 0)
	{
		int index = indexQueue.front();
		indexQueue.pop();

		if (index + 1 == n)
		{
			cout << array[index] << endl;
			break;
		}

		int next[3] = { index + 1, (index + 1) * 2 - 1, (index + 1) * 3 - 1 };
		for (int i = 0; i < 3; i++)
		{
			if (next[i] >= 1000000)
				continue;
			if (array[next[i]] != 0)
				continue;

			array[next[i]] = array[index] + 1;
			indexQueue.push(next[i]);
		}
	}

	return 0;
}