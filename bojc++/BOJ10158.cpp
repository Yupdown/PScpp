#include <bits/stdc++.h>

using namespace std;

int main()
{
	int w, h, p, q, t;
	cin >> w >> h >> p >> q >> t;
	int pp = p + t;
	int qp = q + t;
	cout << (pp / w % 2 ? w - pp % w : pp % w) << " " << (qp / h % 2 ? h - qp % h : qp % h);
}