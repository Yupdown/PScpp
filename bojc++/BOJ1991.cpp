#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

pair<char, char> nodes[128];

void print_tree(char index, int mode)
{
	if (!index)
		return;

	switch (mode) {
	case 0:
		cout << index;
		print_tree(nodes[index].first, mode);
		print_tree(nodes[index].second, mode);
		break;
	case 1:
		print_tree(nodes[index].first, mode);
		cout << index;
		print_tree(nodes[index].second, mode);
		break;
	case 2:
		print_tree(nodes[index].first, mode);
		print_tree(nodes[index].second, mode);
		cout << index;
		break;
	}
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		char a, b, c;
		cin >> a >> b >> c;

		if (b != '.')
			nodes[a].first = b;
		if (c != '.')
			nodes[a].second = c;
	}

	print_tree('A', 0);
	cout << "\n";
	print_tree('A', 1);
	cout << "\n";
	print_tree('A', 2);
	cout << "\n";
}