#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
using int128 = __int128;

int128 mat[]{ 1, 0, 0, 1 };
int128 mat_out[]{ 1, 0, 0, 1 };

void multiply(int128* mat_dst, const int128* mat_src, int128 mod)
{
	int128 mat_temp[4];
	mat_temp[0] = (mat_dst[0] * mat_src[0] + mat_dst[1] * mat_src[2]) % mod;
	mat_temp[1] = (mat_dst[0] * mat_src[1] + mat_dst[1] * mat_src[3]) % mod;
	mat_temp[2] = (mat_dst[2] * mat_src[0] + mat_dst[3] * mat_src[2]) % mod;
	mat_temp[3] = (mat_dst[2] * mat_src[1] + mat_dst[3] * mat_src[3]) % mod;
	copy(begin(mat_temp), end(mat_temp), mat_dst);
}

void power(int128* x, int128 y, const int128* one, int128 mod)
{
	if (y == 0)
		return;
	power(x, y >> 1LL, one, mod);
	multiply(x, x, mod);
	if (y & 1)
		multiply(x, one, mod);
}

int main()
{
	FASTIO();

	long long m, a, c, x0, n, g;
	cin >> m >> a >> c >> x0 >> n >> g;

	mat[0] = a;
	mat[1] = c;

	power(mat_out, n, mat, m);
	cout << static_cast<long long>((mat_out[0] * x0 + mat_out[1]) % m % g);
}