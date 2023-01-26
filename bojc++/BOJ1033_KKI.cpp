#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

bool IsFit(char* rowA, char* rowB, int pivotA, int pivotB, int lenA, int lenB, int* count)
{
	bool isFit = true;
	for (int iAdd = 0; iAdd < lenA; ++iAdd)
	{
		for (int jAdd = 0; jAdd < lenB - pivotB; ++jAdd)
		{
			if ((rowA[pivotA + iAdd] == rowB[pivotB - jAdd]))
			{
				if (rowA[pivotA + iAdd] == '2')
				{
					isFit = false;
				}
			}
		}
	}

	if (isFit)
	{
		int a = lenA + lenB;
		int AA = lenA - pivotA;
		*count = AA + pivotA + pivotB;
		cout << pivotA << " / " << pivotB << "LEN: " <<  *count << endl;
	}

	return isFit;
}

int main()
{
	FASTIO();

	char row[2][100];

	for (int i = 0; i < 2; ++i)
	{
		cin >> row[i];
	}

	int lenA = strlen(row[0]);
	int lenB = strlen(row[1]);
	int countTemp = 0;

	vector<int> results;

	for (int i = 0; i < lenA; ++i)
	{
		for (int j = lenB - 1; j >= 0; --j)
		{
			if (IsFit(row[0], row[1], i, j, lenA, lenB, &countTemp))
			{
				results.push_back(countTemp);
			}
		}
	}

	int minCount = 10000;
	for (int i = 0; i < results.size(); ++i)
	{
		if (minCount > results[i])
		{
			minCount = results[i];
		}
	}

	cout << minCount;
}


// 4 / 0 = 1 / 1
// 4 / 1 = 3 / 1
// 4 / 2 = 5 / 1
// 4 / 3 = 7 / 1