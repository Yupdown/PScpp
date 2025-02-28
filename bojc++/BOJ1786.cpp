#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> get_pi(char* string_p)
{
	size_t n = strlen(string_p);
	vector<int> pi(n, 0);

	for (int i = 1, j = 0; i < n; ++i)
	{
		while (j > 0 && string_p[i] != string_p[j])
			j = pi[j - 1];

		if (string_p[i] == string_p[j])
			pi[i] = ++j;
	}

	return pi;
}

vector<int> kmp(char* string_t, char* string_p)
{
	vector<int> result;
	vector<int> pi = get_pi(string_p);

	size_t n = strlen(string_t);
	size_t m = strlen(string_p);

	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j > 0 && string_t[i] != string_p[j])
			j = pi[j - 1];

		if (string_t[i] == string_p[j])
		{
			if (j + 1 < m)
				++j;
			else
			{
				result.push_back(i - m + 1);
				j = pi[j];
			}
		}
	}

	return result;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	char t[10000000];
	char p[10000000];

	cin.getline(t, sizeof(t));
	cin.getline(p, sizeof(p));

	vector<int> result = kmp(t, p);

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] + 1 << '\n';

	return 0;
}