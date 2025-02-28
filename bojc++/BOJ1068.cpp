#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> a[50], int node)
{
	int r = 0;

	for (int i = 0; i < a[node].size(); i++)
		r += func(a, a[node][i]);

	return r > 0 ? r : 1;
}

int main()
{
	int n, m;
	int in[50];
	vector<int> a[50];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> in[i];
	cin >> m;

	int start = 0;
	for (int i = 0; i < n; i++)
	{
		if (in[i] < 0)
			start = i;
		else if (i != m)
			a[in[i]].push_back(i);
	}

	cout << (m != start ? func(a, start) : 0) << endl;
	return 0;
}