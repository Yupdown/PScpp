#include <iostream>

using namespace std;

int main()
{
	int n;
	pair<int, int> xypairs[50];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> xypairs[i].first >> xypairs[i].second;

	for (int i = 0; i < n; ++i)
	{
		int c = 1;
		for (int j = 0; j < n; ++j)
		{
			if (i != j && xypairs[i].first < xypairs[j].first && xypairs[i].second < xypairs[j].second)
				++c;
		}
		cout << c << (i < n - 1 ? ' ' : '\n');
	}

	return 0;
}