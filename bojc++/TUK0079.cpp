#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

string input;
string filter;

int main()
{
	cin >> input >> filter;

	size_t p = input.find(filter);
	while (p != string::npos)
	{
		input.replace(p, filter.size(), "");
		p = input.find(filter);
	}

	cout << input;
}