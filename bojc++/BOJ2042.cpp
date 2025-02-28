#include <iostream>
#include <climits>
#include <cmath>

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

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int64 table[1000000];
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		cin >> table[i];

	node* root = new node();
	root->create_segment_tree(0, n, table);

	for (int i = 0; i < m + k; ++i)
	{
		int64 a, b, c;
		cin >> a >> b >> c;

		switch (a)
		{
		case 1:
			root->change(0, n, b - 1, c);
			break;

		case 2:
			int64 result = root->find(0, n, b - 1, c);
			cout << result << '\n';
			break;
		}
	}

	delete root;
	return 0;
}