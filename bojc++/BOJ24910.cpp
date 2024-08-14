#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
constexpr int DIMENSIONS = 11;
set<array<int, DIMENSIONS>> obstacles;
const __int128 table[] = { 1, 0, 0, 0, 0, -1, 0, 0, 0, -1, -1, -1, 0, -1, 0, 0 };

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	array<__int128, DIMENSIONS> ret;
	__int128 c = 1;
	for (int i = 0; i < DIMENSIONS - 1; ++i)
		c *= n;
	fill(ret.begin(), ret.end(), c);

	array<int, DIMENSIONS> buffer;
	for (int i = 0; i < k; ++i)
	{
		for (int d = 0; d < DIMENSIONS; ++d)
			cin >> buffer[d];
		obstacles.emplace(buffer);
		for (int d = 0; d < DIMENSIONS; ++d)
		{
			buffer[d] -= 2;
			int flags = 0;
			for (int j = 0; j < 4; ++j)
			{
				flags |= (buffer[d] > 0 && buffer[d] <= n ? obstacles.find(buffer) != obstacles.end() : 1) << j;
				buffer[d] += 1 + (j == 1);
			}
			buffer[d] -= 3;
			ret[d] += table[flags];
		}
	}

	for (int d = 0; d < DIMENSIONS; ++d)
	{
		if (n > 1 && ret[d] != 0)
		{
			stack<int> buffer;
			while (ret[d] > 0)
			{
				buffer.push(ret[d] % 10);
				ret[d] /= 10;
			}
			while (!buffer.empty())
			{
				cout << buffer.top();
				buffer.pop();
			}
			cout << '\n';
		}
		else
			cout << "0\n";
	}
}