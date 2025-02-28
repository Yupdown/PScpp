#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, p[10001];
		cin >> n;
		memset(p, 0, sizeof(p));

		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			cin >> a >> b;
			p[b] = a;
		}

		int c, d;
		cin >> c >> d;

		stack<int> sc, sd;
		do
			sc.push(c);
		while ((c = p[c]) != 0);

		do
			sd.push(d);
		while ((d = p[d]) != 0);

		int r = 0;
		while (!(sc.empty() || sd.empty()))
		{
			int a = sc.top();
			int b = sd.top();

			if (a != b)
				break;

			r = a;

			sc.pop();
			sd.pop();
		}

		cout << r << endl;

		while (!sc.empty())
			sc.pop();
		while (!sd.empty())
			sd.pop();
	}

	return 0;
}