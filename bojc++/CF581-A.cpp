#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[128];
	cin >> s;
	int l = strlen(s);
	cout << (l + (find(s + 1, s + l, '1') != s + l)) / 2;
}