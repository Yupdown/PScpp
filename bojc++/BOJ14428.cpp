#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class node
{
private:
	int value;

	node* element0;
	node* element1;

public:
	~node()
	{
		delete element0;
		delete element1;
	}

	void create_segment_tree(int low, int high, int* table)
	{
		if (high - low < 2)
			value = low;
		else
		{
			int mid = (low + high) / 2;

			element0 = new node();
			element0->create_segment_tree(low, mid, table);
			element1 = new node();
			element1->create_segment_tree(mid, high, table);

			validate(table);
		}
	}

	void change(int low, int high, int a, int b, int* table)
	{
		if (high - low < 2)
			return;
		else
		{
			int mid = (low + high) / 2;

			if (a < mid)
				element0->change(low, mid, a, b, table);
			else
				element1->change(mid, high, a, b, table);

			validate(table);
		}
	}

	int find(int low, int high, int a, int b, int* table)
	{
		if (high - low < 2 || (a <= low && b >= high))
			return value;

		int mid = (low + high) / 2;
		int value0 = -1;
		int value1 = -1;

		if (a < mid)
			value0 = element0->find(low, mid, a, b, table);
		if (b > mid)
			value1 = element1->find(mid, high, a, b, table);

		if (value0 < 0)
			return value1;
		if (value1 < 0)
			return value0;

		return table[value0] <= table[value1] ? value0 : value1;
	}

	void validate(int* table)
	{
		int value0 = element0->value;
		int value1 = element1->value;
		value = table[value0] <= table[value1] ? value0 : value1;
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int table[100000];
	int n, m;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	node* root = new node();
	root->create_segment_tree(0, n, table);

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		switch (a)
		{
		case 1:
			table[b - 1] = c;
			root->change(0, n, b - 1, c, table);
			break;

		case 2:
			int result = root->find(0, n, b - 1, c, table) + 1;
			cout << result << '\n';
			break;
		}
	}

	delete root;
	return 0;
}