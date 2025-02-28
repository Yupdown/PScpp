#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class node
{
private:
	pair<int, int> value;

	node* left;
	node* right;

public:
	~node()
	{
		delete left;
		delete right;
	}

	void create_segment_tree(int low, int high, int* table)
	{
		if (high - low < 2)
		{
			value.first = table[low];
			value.second = table[low];
		}
		else
		{
			int mid = (low + high) / 2;

			left = new node();
			left->create_segment_tree(low, mid, table);
			right = new node();
			right->create_segment_tree(mid, high, table);

			value.first = min(left->value.first, right->value.first);
			value.second = max(left->value.second, right->value.second);
		}
	}

	pair<int, int> find(int low, int high, int a, int b)
	{
		if (high - low < 2 || (a <= low && b >= high))
			return value;

		int mid = (low + high) / 2;
		pair<int, int> leftResult = { INT_MAX, INT_MIN };
		pair<int, int> rightResult = { INT_MAX, INT_MIN };

		if (a < mid)
			leftResult = left->find(low, mid, a, b);
		if (b > mid)
			rightResult = right->find(mid, high, a, b);

		return { min(leftResult.first, rightResult.first), max(leftResult.second, rightResult.second) };
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int table[100000];
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	node* root = new node();
	root->create_segment_tree(0, n, table);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		pair<int, int> result = root->find(0, n, a - 1, b);
		cout << result.first << ' ' << result.second << '\n';
	}

	delete root;
	return 0;
}