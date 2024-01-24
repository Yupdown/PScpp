#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int table[1000][1000];

int get_result(int* histogram, int n)
{
	int result = 0;
	stack<int> rectangles;

	rectangles.push(-1);
	for (int i = 0; i < n + 1; i++)
	{
		while (!rectangles.empty())
		{
			int top = rectangles.top();
			if ((top >= 0 ? histogram[top] : 0) <= (i < n ? histogram[i] : 0))
				break;

			rectangles.pop();
			result = max(result, (i - rectangles.top() - 1) * histogram[top]);
		}
		rectangles.push(i);
	}

	return result;
}

int main()
{
	FASTIO();

	int n, m;
	cin >> n >> m;
	while (n && m)
	{
		for (int i = 0; i < n * m; ++i)
		{
			cin >> table[i / m][i % m];
			if (i >= m)
				table[i / m][i % m] *= (table[i / m - 1][i % m] + 1);
		}

		int vmax = 0;
		for (int i = 0; i < n; ++i)
			vmax = max(vmax, get_result(table[i], m));
		cout << vmax << '\n';
		cin >> n >> m;
	}
}