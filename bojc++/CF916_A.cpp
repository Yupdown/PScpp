#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int problem_log[26];
char input[512];

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		memset(problem_log, 0, sizeof(problem_log));

		int n;
		cin >> n >> input;

		for (int i = 0; i < n; ++i)
			++problem_log[input[i] - 'A'];

		int r = 0;
		for (int i = 0; i < 26; ++i)
			r += problem_log[i] > i;

		cout << r << "\n";
	}
}