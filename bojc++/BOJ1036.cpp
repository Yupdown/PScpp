#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> digit[50];
array<int, 64> gain[36];
array<int, 64> sum;

int main()
{
	FASTIO();

	int n, k;
	cin >> n;

	char buffer[64];
	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;
		int len = strlen(buffer);

		digit[i].resize(len);
		for (int j = 0; j < len; ++j)
			digit[i][len - j - 1] = isdigit(buffer[j]) ? buffer[j] - '0' : buffer[j] - 'A' + 10;
	}

	for (int i = 0; i < 36; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < digit[j].size(); ++k)
			{
				if (digit[j][k] == i)
					gain[i][k] += 35 - i;
			}
		}
	}

	cin >> k;

	for (int i = 0; i < 36; ++i)
	{
		int carry = 0;
		for (int j = 0; j < 64; ++j)
		{
			gain[i][j] += carry;
			carry = gain[i][j] / 36;
			gain[i][j] %= 36;
		}
	}

	sort(begin(gain), end(gain), [](const array<int, 64>& lhs, const array<int, 64>& rhs) { return lexicographical_compare(rbegin(lhs), rend(lhs), rbegin(rhs), rend(rhs), greater<int>()); });

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < digit[i].size(); ++j)
			sum[j] += digit[i][j];
	}
	for (int i = 0; i < 64; ++i)
	{
		for (int j = 0; j < k; ++j)
			sum[i] += gain[j][i];
	}

	stack<int> result;
	int carry = 0;
	for (int i = 0; i < 64; ++i)
	{
		carry += sum[i];
		result.push(carry % 36);
		carry /= 36;
	}

	while (!result.empty() && result.top() == 0)
		result.pop();

	if (result.empty())
		cout << 0;
	else
	{
		while (!result.empty())
		{
			int top = result.top();
			result.pop();
			cout << static_cast<char>(top < 10 ? top + '0' : top - 10 + 'A');
		}
	}
}