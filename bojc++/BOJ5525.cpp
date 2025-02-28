#include <bits/stdc++.h>
#define FASTIO() cin.tie(0)->ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n, m;
	char s[1000001];

	cin >> n >> m;
	cin >> s;

	int p = 0, r = 0;
	char* ptr = s;

	while (ptr < s + m)
	{
		if (*ptr == 'I')
		{
			++p;
			if (*(ptr + 1) == 'O')
				++ptr;
			else
			{
				r += max(p - n, 0);
				p = 0;
			}
		}
		else
		{
			r += max(p - n, 0);
			p = 0;
		}

		++ptr;
	}
	r += max(p - n, 0);

	cout << r << '\n';
	return 0;
}