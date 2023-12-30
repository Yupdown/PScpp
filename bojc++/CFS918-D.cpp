#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
char buffer[1 << 18];
char output[1 << 18];

inline bool vowel(char c)
{
	return c == 'a' || c == 'e';
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n >> buffer;

		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			bool flag = false;
			if (i < n - 1 && !vowel(buffer[i]) && !vowel(buffer[i + 1]))
				flag = true;
			if (i < n - 2 && vowel(buffer[i]) && !vowel(buffer[i + 1]) && vowel(buffer[i + 2]))
				flag = true;
			output[j++] = buffer[i];
			if (flag)
				output[j++] = '.';
		}
		output[j] = 0;
		cout << output << '\n';
	}
}