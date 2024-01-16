#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

char s[1024];
char t[1024];

int main()
{
	FASTIO();

	cin >> s >> t;
	int ns = strlen(s);
	int nt = strlen(t);

	for (int i = nt; i > ns; --i)
	{
		if (t[i - 1] == 'B')
			reverse(t, t + i - 1);
	}

	cout << (strncmp(s, t, ns) == 0);
}