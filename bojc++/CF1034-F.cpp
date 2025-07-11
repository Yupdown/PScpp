#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int memo[1 << 18];
int prim[1 << 18];
bool flag[1 << 18];

void Eratos(int n)
{
	/*  만일 n이 1보다 작거나 같으면 함수 종료 */
	if (n <= 1) return;

	/*  배열초기화: 처음엔 모두 소수로 보고 true값을 줌	*/
	for (int i = 2; i <= n; i++)
		prim[i] = true;

	/*	에라토스테네스의 체에 맞게 소수를 구함
		만일, PrimeArray[i]가 true이면 i 이후의 i 배수는 약수로 i를
		가지고 있는 것이 되므로 i 이후의 i 배수에 대해 false값을 준다.
		PrimeArray[i]가 false이면 i는 이미 소수가 아니므로 i의 배수 역시
		소수가 아니게 된다. 그러므로 검사할 필요도 없다.
		또한 i*k (k < i) 까지는 이미 검사되었으므로 j시작 값은 i*2에서 i*i로 개선할 수 있다.
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