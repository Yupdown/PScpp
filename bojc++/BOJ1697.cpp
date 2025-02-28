#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int array[100001] = { 0 };

	int n, k;
	cin >> n >> k;

	queue<int> indexQueue;
	indexQueue.push(n);

	while (indexQueue.size() > 0)
	{
		int index = indexQueue.front();
		indexQueue.pop();

		if (index == k)
		{
			cout << array[index] << endl;
			break;
		}

		int next[3] = { index + 1, index - 1, index * 2 };
		for (int i = 0; i < 3; i++)
		{
			if (next[i] >= 100001 || next[i] < 0)
				continue;
			if (array[next[i]] != 0)
				continue;

			array[next[i]] = array[index] + 1;
			indexQueue.push(next[i]);
		}
	}

	return 0;
}