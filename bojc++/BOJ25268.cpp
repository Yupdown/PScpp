#include <iostream>

using namespace std;

char* vowel = "aeiou";
char* consonant = "bcdfghjklmnpqrstvwxyz";

int function(char* str, int i, int c)
{
	bool v = i / 2 % 2;
	for (int j = 0; j < (v ? 5 : 21) && c > 0; ++j)
	{
		str[i] = v ? vowel[j] : consonant[j];
		if (i < 4)
			c = function(str, i + 1, c);
		else
		{
			cout << str << '\n';
			--c;
		}
	}

	return c;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	char str[32] = "aa";
	int n;
	cin >> n;

	function(str, 0, n);
	return 0;
}