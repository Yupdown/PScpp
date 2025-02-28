#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	pair<int, int> convos[100000];

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> convos[i].first >> convos[i].second;

	sort(convos, convos + n, [](const pair<int, int>& a, const pair<int, int>& b) -> bool { return a.second == b.second ? a.first < b.first : a.second < b.second; });

	int m = 0, r = 0;
	for (int i = 0; i < n; i++)
	{
		if (convos[i].first < m)
			continue;
		m = convos[i].second;
		r++;
	}

	cout << r << endl;
	return 0;
}