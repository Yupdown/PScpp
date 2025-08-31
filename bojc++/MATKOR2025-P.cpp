#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	if (n == 1)
		cout << "1\n1";
	else if (n == 2)
		cout << "2\n1 2";
	else
	{
		int ret = n / 3 + 1;
		int plu = n % 3 != 0;
		cout << ret + plu << "\n";
		int val = (ret - 1) / 2 * 3 + 1;
		int lr = 0;
		int rr = 2;
		for (int i = 0; i < ret; ++i)
		{
			if (i & 1)
			{
				cout << val + rr << " ";
				rr += 3;
			}
			else
			{
				cout << val - lr << " ";
				lr += 3;
			}
		}
		if (plu > 0)
			cout << n;
	}
}