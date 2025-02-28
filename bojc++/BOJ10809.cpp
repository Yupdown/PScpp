#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char string[128];
	int alphabets[26];

	cin >> string;
	memset(alphabets, -1, 26 * sizeof(int));

	for (int i = 0; string[i] != 0; i++)
	{
		int alphabet = string[i] % 'a';
		if (alphabets[alphabet] < 0)
			alphabets[alphabet] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << alphabets[i] << ' ';
	cout << endl;
	return 0;
}