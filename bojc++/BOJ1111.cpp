#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[50];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	if (n == 1)
		cout << "A";
	else if (n == 2)
	{
		if (table[0] == table[1])
			cout << table[0];
		else
			cout << "A";
	}
	else
	{
		int x1 = table[0];
		int x2 = table[1];
		int x3 = table[2];
		if (x1 == x2)
		{
			if (x2 != x3)
				cout << "B";
			else if (count(table, table + n, table[0]) == n)
				cout << table[0];
			else
				cout << "B";
		}
		else if ((x3 - x2) % (x2 - x1))
			cout << "B";
		else
		{
			int a = (x3 - x2) / (x2 - x1);
			int b = x2 - x1 * a;
			bool flag = true;
			for (int i = 2; i < n - 1; ++i)
				flag &= table[i + 1] == table[i] * a + b;
			if (flag)
				cout << table[n - 1] * a + b;
			else
				cout << "B";
		}
	}
}