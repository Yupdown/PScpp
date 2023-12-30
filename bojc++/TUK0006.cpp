#include <bits/stdc++.h>

using namespace std;

char table[10000];

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	int j = 0, r = 1;
	for (int i = 0; i < m; ++i)
	{
		int d;
		cin >> d;
		switch (table[j])
		{
		case '+':
			if (j + d < n)
				j += d;
			break;
		case '-':
			if (j - d >= 0)
				j -= d;
			break;
		}
		r += j == 0;
	}
	cout << r;
}