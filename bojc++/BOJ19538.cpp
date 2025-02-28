#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t[200000];
int cnt[200000];
vector<int> edge[200000];
queue<int> infection;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int ni;
		while (cin >> ni && ni > 0)
			edge[i].push_back(ni - 1);
		t[i] = -1;
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int mi;
		cin >> mi;
		t[mi - 1] = 0;
		infection.push(mi - 1);
	}

	queue<int> buffer;

	int c = 0;
	while (!infection.empty())
	{
		for (int i = infection.size(); i > 0; --i)
		{
			int node = infection.front();
			infection.pop();

			for (int j = 0; j < edge[node].size(); ++j)
			{
				int near = edge[node][j];
				cnt[near] += 1;

				buffer.push(near);
			}
		}

		while (!buffer.empty())
		{
			int near = buffer.front();
			buffer.pop();

			if (cnt[near] * 2 >= edge[near].size() && t[near] < 0)
			{
				t[near] = c + 1;
				infection.push(near);
			}
		}

		++c;
	}

	for (int i = 0; i < n; ++i)
		cout << t[i] << (i + 1 < n ? ' ' : '\n');

	return 0;
}