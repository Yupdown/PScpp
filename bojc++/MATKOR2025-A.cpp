#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;

	if (n % k == 0)
	{
		int ret = 0;
		for (int i = 0; i < n / k; ++i)
		{
			cout << "? ";
			for (int j = 0; j < k; ++j)
				cout << i * k + j + 1 << " ";
			cout << endl << flush;
			int v;
			cin >> v;
			ret += v;
		}
		cout << "! " << ret << endl << flush;
	}
	else if (k == 2)
	{
		int ret = 0;
		for (int i = 0; i < n / k - 1; ++i)
		{
			cout << "? " << i * k + 1 << " " << i * k + 2 << endl << flush;
			int v;
			cin >> v;
			ret += v;
		}
		int ab, bc, ac;
		cout << "? " << n - 2 << " " << n - 1 << endl << flush;
		cin >> ab;
		cout << "? " << n - 1 << " " << n << endl << flush;
		cin >> bc;
		cout << "? " << n - 2 << " " << n << endl << flush;
		cin >> ac;
		ret += (ab + bc + ac) / 2;
		cout << "! " << ret << endl << flush;
	}
}