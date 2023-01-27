#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	stack<int> s;
	queue<char> r;
	int n;
	cin >> n;

	s.push(0);
	for (int i = 0, c = 0; i < n; ++i) {
		int v;
		cin >> v;
		while (s.top() < v) {
			s.push(++c);
			r.push('+');
		}
		if (s.top() == v) {
			s.pop();
			r.push('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	
	while (!r.empty()) {
		cout << r.front() << '\n';
		r.pop();
	}
}