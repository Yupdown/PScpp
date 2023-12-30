#include <bits/stdc++.h>

using namespace std;

vector<int> result;

bool solution(int s, int k)
{
	if (result.size() == k)
	{
		int sum = 0;
		for (auto element : result)
			sum += element;
		if (sum == s)
			return true;
		return false;
	}

	int p = result.size() - 1;
	for (int n = 1; n <= result[p]; ++n)
	{
		if (result[p] % n == 0)
		{
			result.push_back(n);
			result[p] /= n;
			if (solution(s, k))
				return true;
			result.pop_back();
			result[p] *= n;
		}
	}
	return false;
}

int main()
{
	int s, p, k;
	cin >> s >> p >> k;
	result.push_back(p);

	if (solution(s, k))
	{
		sort(result.begin(), result.end());
		for (int element : result)
			cout << element << ' ';
	}
	else
		cout << "NO";
}