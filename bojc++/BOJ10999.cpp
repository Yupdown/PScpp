#include <iostream>

using namespace std;
typedef long long int64;

class segment_tree
{
public:
	class node
	{
	private:
		int64 value;

		node* element0;
		node* element1;

		int64 lazy;

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

		void change(int low, int high, int a, int b, int64 c)
		{
			if (lazy != 0)
				apply_lazy(low, high);

			if (a <= low && b >= high)
			{
				value += (int64)(high - low) * c;

				if (high - low > 1)
				{
					element0->lazy += c;
					element1->lazy += c;
				}
			}
			else
			{
				int mid = (low + high) / 2;

				if (element0->lazy != 0)
					element0->apply_lazy(low, mid);
				if (element1->lazy != 0)
					element1->apply_lazy(mid, high);

				if (a < mid)
					element0->change(low, mid, a, b, c);
				if (b > mid)
					element1->change(mid, high, a, b, c);

				value = element0->value + element1->value;
			}
		}

		int64 find(int low, int high, int a, int b)
		{
			if (lazy != 0)
				apply_lazy(low, high);

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

		void apply_lazy(int low, int high)
		{
			value += (int64)(high - low) * lazy;
			if (high - low > 1)
			{
				element0->lazy += lazy;
				element1->lazy += lazy;
			}
			lazy = 0;
		}
	};

private:
	node* root;
	int size;

public:
	~segment_tree()
	{
		delete root;
	}

	segment_tree(int64* table, int size) : size(size)
	{
		root = new node();
		root->create_segment_tree(0, size, table);
	}

	void change(int a, int b, int64 c)
	{
		root->change(0, size, a, b, c);
	}

	int64 find(int a, int b)
	{
		return root->find(0, size, a, b);
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

	segment_tree* tree = new segment_tree(table, n);

	for (int i = 0; i < m + k; ++i)
	{
		int64 a, b, c, d;
		cin >> a;

		switch (a)
		{
		case 1:
			cin >> b >> c >> d;
			tree->change(b - 1, c, d);
			break;

		case 2:
			cin >> b >> c;
			int64 result = tree->find(b - 1, c);
			cout << result << '\n';
			break;
		}
	}

	delete tree;
	return 0;
}