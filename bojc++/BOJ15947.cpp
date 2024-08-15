#include <bits/stdc++.h>

using namespace std;

string func(int k)
{
	if (k >= 5)
		return "tu+ru*" + to_string(k);
	string s = "tu";
	while (k--)
		s += "ru";
	return s;
}

string temp[] = {
	"baby",
	"sukhwan",
	"2",
	"1",
	"very",
	"cute",
	"2",
	"1",
	"in",
	"bed",
	"2",
	"1",
	"baby",
	"sukhwan"
};

int main()
{
	int n;
	cin >> n;

	string s = temp[(n - 1) % 14];
	if (isdigit(s[0]))
		s = func((n - 1) / 14 + s[0] - '0');

	cout << s;
}