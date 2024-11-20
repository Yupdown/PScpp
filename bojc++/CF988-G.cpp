#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

bool che[1 << 20];
long long table[1 << 20];
vector<long long> primes;
using iter_t = set<long long>::const_iterator;

// 1번째 노드에서 i번째 노드로 갈 수 있는 경로의 개수는, 자신보다 작으면서 ai가 서로소가 아닌 노드로 갈 수 있는 경로의 수를 모두 더한 것이다.
// 브루트 포스를 이용하여 서로소인지 판단하면 TLE. 동적 계획법을 이용하여 구해야 한다.
// table[i] 는 현재 노드보다 작은 노드 중 i로 나누어떨어질 수 있는 ai에 대한 경로의 수의 합
// 소인수분해를 하여 소수만 추려낸 후 이를 경로의 수를 구하는데 쓸 수 있어 빠르다.
// 그러나, 여러가지의 소수의 곱으로 나타내어진 ai는 합하는데 중복이 될 수 있다. (6과 12의 경우, 모두 2와 3의 곱으로 나타낼 수 있는데, 한 쌍임에도 불구하고 2번 더해질 수 있다.)
// 그래서, '포함-배제의 원리'를 이용하여 두 소수의 곱으로 나타낸 수에 대해서는 뺄셈 연산을, 세 소수의 곱으로 나타낸 수에 대해서는 덧셈 연산을 적용하는 식으로 소수의 합성 여부와 관련없이 모두 한번씩만 더할 수 있게 한다.

long long get_table(int i, long long v, iter_t iter, iter_t end)
{
	if (iter == end)
	{
		if (i & 1)
			return table[v];
		else
			return -table[v];
	}
	return get_table(i + 1, v * *iter, next(iter), end) + get_table(i, v, next(iter), end);
}

void insert_table(long long d, long long v, iter_t iter, iter_t end)
{
	if (iter == end)
	{
		if (v > 1)
			table[v] += d;
		return;
	}
	insert_table(d, v * *iter, next(iter), end);
	insert_table(d, v, next(iter), end);
}

int main()
{
	FASTIO();

	for (int i = 2; i < 1 << 20; ++i)
	{
		if (che[i])
			continue;
		for (int j = i * 2; j < 1 << 20; j += i)
			che[j] = true;
	}
	for (int i = 2; i < 1 << 20; ++i)
	{
		if (!che[i])
			primes.push_back(i);
	}
	int n;
	cin >> n;
	set<long long> factors;
	long long ret;
	for (int i = 0; i < n; ++i)
	{
		long long v;
		cin >> v;

		factors.clear();
		while (che[v])
		{
			for (auto p : primes)
			{
				if (v % p == 0)
				{
					factors.insert(p);
					v /= p;
					break;
				}
			}
		}
		factors.insert(v);
		if (i)
			ret = get_table(0, 1, factors.begin(), factors.end()) % 998244353;
		else
			ret = 1;
		insert_table(ret, 1, factors.begin(), factors.end());
	}
	cout << ret;
}