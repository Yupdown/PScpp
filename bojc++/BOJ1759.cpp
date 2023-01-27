#include <bits/stdc++.h>

using namespace std;

void combination(const char* a, char* t, int l, int c, int i, int cc, int vc)
{
	if (cc + vc < l) {
		for (int j = i; j < c; ++j) {
			bool flag = false;
			switch (a[j]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				flag = true;
				break;
			}
			t[cc + vc] = a[j];
			combination(a, t, l, c, j + 1, cc + !flag, vc + flag);
		}
	}
	else {
		if (cc >= 2 && vc >= 1)
			cout << t << '\n';
	}
}

int main()
{
	char a[16], t[16];
	int l, c;
	cin >> l >> c;

	for (int i = 0; i < c; ++i)
		cin >> a[i];

	sort(a, a + c);

	t[l] = 0;
	combination(a, t, l, c, 0, 0, 0);
}