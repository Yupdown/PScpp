#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

vector<int> sequence;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	sequence.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> sequence[i];

	int sum = 0;
	sort(sequence.begin(), sequence.end(), less<int>());
	while (sequence.size() > 1)
	{
		int lhs = sequence.end()[-2];
		int rhs = sequence.end()[-1];

		if (lhs <= 0)
			break;

		sum += max(lhs * rhs, lhs + rhs);

		sequence.pop_back();
		sequence.pop_back();
	}

	sort (sequence.begin(), sequence.end(), greater<int>());
	while (sequence.size() > 1)
	{
		int lhs = sequence.end()[-2];
		int rhs = sequence.end()[-1];

		if (lhs > 0)
			break;

		sum += lhs * rhs;

		sequence.pop_back();
		sequence.pop_back();
	}

	for (int value : sequence)
		sum += value;

	cout << sum;
}