#include <iostream>
#include <queue>

using namespace std;

int main()
{
	const int DIMENSION = 11;

	int axisSizes[DIMENSION], size = 1;
	for (int i = 0; i < DIMENSION; i++)
	{
		cin >> axisSizes[i];
		size *= axisSizes[i];
	}

	int map[1000000];
	for (int i = 0; i < size; i++)
		cin >> map[i];

	queue<pair<int, int>> ripePositions;

	for (int i = 0; i < size; i++)
	{
		if (map[i] == 1)
			ripePositions.push({ i, 0 });
	}

	int count = 0;
	while (!ripePositions.empty())
	{
		pair<int, int> ripePosition = ripePositions.front();
		ripePositions.pop();

		queue<int> nextIndexes;
		for (int i = 0, offset = 1; i < DIMENSION; offset *= axisSizes[i++])
		{
			int axisCoordinate = (ripePosition.first / offset) % axisSizes[i];

			if (axisCoordinate > 0)
				nextIndexes.push(ripePosition.first - offset);
			if (axisCoordinate < axisSizes[i] - 1)
				nextIndexes.push(ripePosition.first + offset);
		}

		while (!nextIndexes.empty())
		{
			int nextIndex = nextIndexes.front();
			nextIndexes.pop();

			if (map[nextIndex] == 1 || map[nextIndex] == -1)
				continue;

			ripePositions.push({ nextIndex, ripePosition.second + 1 });
			map[nextIndex] = 1;
		}

		count = ripePosition.second;
	}

	for (int i = 0; i < size; i++)
	{
		if (map[i] == 0)
			count = -1;
	}

	cout << count << endl;

	return 0;
}