#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int64 = long long;

constexpr int64 MOD = 1000000007;
int64 mat[]{ 4, -1, 1, 0 };
int64 mat_out[]{ 1, 0, 0, 1 };

void multiply(int64* mat_dst, const int64* mat_src)
{
	int64 mat_temp[4];
	mat_temp[0] = (mat_dst[0] * mat_src[0] + mat_dst[1] * mat_src[2]) % MOD;
	mat_temp[1] = (mat_dst[0] * mat_src[1] + mat_dst[1] * mat_src[3]) % MOD;
	mat_temp[2] = (mat_dst[2] * mat_src[0] + mat_dst[3] * mat_src[2]) % MOD;
	mat_temp[3] = (mat_dst[2] * mat_src[1] + mat_dst[3] * mat_src[3]) % MOD;
	copy(begin(mat_temp), end(mat_temp), mat_dst);
}

void power(int64* x, int64 y, const int64* one)
{
	if (y == 0)
		return;
	power(x, y >> 1LL, one);
	multiply(x, x);
	if (y & 1)
		multiply(x, one);
}

int main()
{
	FASTIO();

	int64 n;
	cin >> n;

	if (n & 1LL)
		cout << 0;
	else
	{
		power(mat_out, n >> 1LL, mat);
		cout << (MOD * 2 + mat_out[0] + mat_out[1]) % MOD;
	}
}