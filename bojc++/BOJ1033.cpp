#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int result[10];
vector<pair<int, pair<int, int>>> edge[10];

int gcd(int a, int b)
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

void solution(int n, int c, int l)
{
	for (pair<int, pair<int, int>> iter : edge[c])
	{
		if (iter.first == l)
			continue;

		int gcdv = gcd(iter.second.first, iter.second.second);
		int a = iter.second.first / gcdv;
		int b = iter.second.second / gcdv;
		gcdv = gcd(result[c], a);
		
		int v = result[c] * b;
		for (int i = 0; i < 10; ++i)
			result[i] *= a / gcdv;
		result[iter.first] = v / gcdv;

		solution(n, iter.first, c);
	}

}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;

		edge[a].push_back(make_pair(b, make_pair(p, q)));
		edge[b].push_back(make_pair(a, make_pair(q, p)));
	}

	result[0] = 1;
	solution(n, 0, 0);

	for (int i = 0; i < n; ++i)
		cout << result[i] << ' ';
	cout << endl;

	return 0;
}