#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[1 << 18];
int prim[1 << 18];
bool flag[1 << 18];

void Eratos(int n)
{
	/*  ���� n�� 1���� �۰ų� ������ �Լ� ���� */
	if (n <= 1) return;

	/*  �迭�ʱ�ȭ: ó���� ��� �Ҽ��� ���� true���� ��	*/
	for (int i = 2; i <= n; i++)
		prim[i] = true;

	/*	�����佺�׳׽��� ü�� �°� �Ҽ��� ����
		����, PrimeArray[i]�� true�̸� i ������ i ����� ����� i��
		������ �ִ� ���� �ǹǷ� i ������ i ����� ���� false���� �ش�.
		PrimeArray[i]�� false�̸� i�� �̹� �Ҽ��� �ƴϹǷ� i�� ��� ����
		�Ҽ��� �ƴϰ� �ȴ�. �׷��Ƿ� �˻��� �ʿ䵵 ����.
		���� i*k (k < i) ������ �̹� �˻�Ǿ����Ƿ� j���� ���� i*2���� i*i�� ������ �� �ִ�.
	*/
	for (int i = 2; i * i <= n; i++)
	{
		if (prim[i])
		{
			for (int j = i * i; j <= n; j += i)
				prim[j] = false;
		}
	}
}

int main()
{
	FASTIO();

	Eratos((1 << 18) - 1);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
			memo[i] = i;

		map<int, vector<int>> bukkit;
		memset(flag, 0, n + 1);

		for (int i = 2; i * 2 <= n; ++i)
		{
			if (!prim[i])
				continue;
			bukkit[i].push_back(i);
			bukkit[i].push_back(i * 2);
			flag[i] = true;
			flag[i * 2] = true;
		}
		for (int i = 2; i * 2 <= n; ++i)
		{
			if (!prim[i])
				continue;
			for (int j = i * 3; j <= n; j += i)
			{
				if (!flag[j])
					bukkit[i].push_back(j);
				flag[j] = true;
			}
		}
		for (const auto& [k, v] : bukkit)
		{
			int temp = memo[k];
			for (int i = 0; i < v.size() - 1; ++i)
				memo[v[i]] = memo[v[i + 1]];
			memo[v.back()] = temp;
		}

		for (int i = 1; i <= n; ++i)
			cout << memo[i] << " ";
		cout << "\n";
	}
}