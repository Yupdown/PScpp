#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
string src;
string dst;
int memo[128];

int main()
{
	FASTIO();

	cin >> src;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> dst;
		memset(memo, 0, sizeof(memo));
		memo[0] = 1;
		for (int i = 0; i < src.size(); ++i)
		{
			if (src[i] == '*')
			{
				for (int j = 0; j < dst.size(); ++j)
					memo[j + 1] = max(memo[j], memo[j + 1]);
			}
			else
			{
				for (int j = dst.size() - 1; j >= 0; --j)
					memo[j + 1] = memo[j] * (src[i] == dst[j]);
				memo[0] = 0;
			}
		}

		if (memo[dst.size()])
			cout << dst << '\n';
	}
}