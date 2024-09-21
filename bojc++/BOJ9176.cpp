#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// Preprocessing code
//using int64 = long long;
//
//vector<vector<int64>> table(2);
//
//int main()
//{
//	for (int i = 2; i < 63; ++i)
//	{
//		bool flag = false;
//		for (int j = 2; j * j <= i; ++j)
//			flag |= i % j == 0;
//		if (flag)
//		{
//			table.emplace_back();
//			continue;
//		}
//		int64 n = (1LL << i) - 1;
//		vector<int64> primes;
//		while (n > 1)
//		{
//			bool flag = false;
//			for (int64 k = 2; k * k <= n; ++k)
//			{
//				if (n % k == 0)
//				{
//					primes.push_back(k);
//					n /= k;
//					flag = true;
//					break;
//				}
//			}
//			if (!flag)
//			{
//				primes.push_back(n);
//				break;
//			}
//		}
//
//		sort(primes.begin(), primes.end());
//		table.emplace_back(move(primes));
//	}
//	for (int i = 2; i < 63; ++i)
//	{
//		if (table[i].size() < 2)
//			continue;
//		cout << "s[" << i << "] = \"";
//		cout << table[i][0];
//		for (int j = 1; j < table[i].size(); ++j)
//			cout << " * " << table[i][j];
//		cout << " = " << ((1LL << i) - 1) << " = ( 2 ^ " << i << " ) - 1\";\n";
//	}
//}

int main()
{
	string s[64]{};
	s[11] = "23 * 89 = 2047 = ( 2 ^ 11 ) - 1";
	s[23] = "47 * 178481 = 8388607 = ( 2 ^ 23 ) - 1";
	s[29] = "233 * 1103 * 2089 = 536870911 = ( 2 ^ 29 ) - 1";
	s[37] = "223 * 616318177 = 137438953471 = ( 2 ^ 37 ) - 1";
	s[41] = "13367 * 164511353 = 2199023255551 = ( 2 ^ 41 ) - 1";
	s[43] = "431 * 9719 * 2099863 = 8796093022207 = ( 2 ^ 43 ) - 1";
	s[47] = "2351 * 4513 * 13264529 = 140737488355327 = ( 2 ^ 47 ) - 1";
	s[53] = "6361 * 69431 * 20394401 = 9007199254740991 = ( 2 ^ 53 ) - 1";
	s[59] = "179951 * 3203431780337 = 576460752303423487 = ( 2 ^ 59 ) - 1";

	int k;
	cin >> k;
	for (int i = 0; i <= k; ++i)
	{
		if (!s[i].empty())
			cout << s[i] << '\n';
	}
}