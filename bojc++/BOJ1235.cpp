#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int compare(char* a, char* b, int l)
{
	int k = 0;
	while (++k <= l)
	{
		if (a[l - k] != b[l - k])
			break;
	}
	return k;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	char str[1000][128];
	for (int i = 0; i < n; ++i)
		cin >> str[i];

	int l = strlen(str[0]);
	int k = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
			k = max(k, compare(str[i], str[j], l));
	}
	cout << k << '\n';
	return 0;
}