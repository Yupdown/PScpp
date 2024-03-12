#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int A[1024];
int B[1024];
int C[2048];

int main()
{
	FASTIO();

	int b, n, m;
	cin >> b >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> A[i];
	for (int i = 0; i < m; ++i)
		cin >> B[i];

	reverse(A, A + n);
	reverse(B, B + m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			C[i + j] += A[i] * B[j];
	}

	for (int i = 1; i < 2048; ++i)
	{
		C[i] += C[i - 1] / b;
		C[i - 1] %= b;
	}

	int p = 2047;
	while (p > 0 && C[p] == 0)
		--p;

	cout << p + 1 << '\n';
	while (p >= 0)
		cout << C[p--] << ' ';
}