#include <bits/stdc++.h>
#include <array>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
typedef long long int64;

class node
{
private:
	int64 value;

	node* element0;
	node* element1;

public:
	~node()
	{
		delete element0;
		delete element1;
	}

	void create_segment_tree(int low, int high, int64* table)
	{
		if (high - low < 2)
			value = table[low];
		else
		{
			int mid = (low + high) / 2;

			element0 = new node();
			element0->create_segment_tree(low, mid, table);
			element1 = new node();
			element1->create_segment_tree(mid, high, table);

			value = element0->value + element1->value;
		}
	}

	void change(int low, int high, int a, int64 b)
	{
		if (high - low < 2)
			value = b;
		else
		{
			int mid = (low + high) / 2;

			if (a < mid)
				element0->change(low, mid, a, b);
			else
				element1->change(mid, high, a, b);

			value = element0->value + element1->value;
		}
	}

	int64 find(int low, int high, int a, int b)
	{
		if (high - low < 2 || (a <= low && b >= high))
			return value;

		int mid = (low + high) / 2;
		int64 result0 = 0;
		int64 result1 = 0;

		if (a < mid)
			result0 = element0->find(low, mid, a, b);
		if (b > mid)
			result1 = element1->find(mid, high, a, b);

		return result0 + result1;
	}
};

int64 input[100000];
vector<array<int64, 2>> q1;
vector<array<int64, 5>> q2;

int main()
{
	FASTIO();

	int n, m;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> input[i];

	node* root = new node();
	root->create_segment_tree(0, n, input);

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int64 a, b, c, d;
		cin >> a;

		switch (a)
		{
		case 1:
			cin >> b >> c;
			q1.push_back(array<int64, 2>{ b - 1, c });
			break;

		case 2:
			cin >> b >> c >> d;
			q2.push_back(array<int64, 5>{ i, b, c - 1, d, 0 });
			break;
		}
	}

	sort(q2.begin(), q2.end(), [](const array<int64, 5>& lhs, const array<int64, 5>& rhs) -> bool { return lhs[1] < rhs[1]; });

	int k = 0;
	for (auto& query : q2)
	{
		while (k < (int)query[1])
		{
			root->change(0, n, (int)q1[k][0], q1[k][1]);
			++k;
		}
		query[4] = root->find(0, n, (int)query[2], (int)query[3]);
	}

	sort(q2.begin(), q2.end(), [](const array<int64, 5>& lhs, const array<int64, 5>& rhs) -> bool { return lhs[0] < rhs[0]; });

	for (const auto& query : q2)
		cout << query[4] << "\n";

	delete root;
	return 0;
}