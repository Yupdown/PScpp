#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long int64;

struct vector2d
{
	int64 x;
	int64 y;

	vector2d() : vector2d(0LL, 0LL) {}
	vector2d(int64 x, int64 y)
	{
		this->x = x;
		this->y = y;
	}

	vector2d operator+(const vector2d& other)
	{
		return vector2d(x + other.x, y + other.y);
	}

	vector2d operator-(const vector2d& other)
	{
		return vector2d(x - other.x, y - other.y);
	}

	vector2d operator+()
	{
		return vector2d(x, y);
	}

	vector2d operator-()
	{
		return vector2d(-x, -y);
	}
};

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

	void create_segment_tree(int low, int high)
	{
		value = 0;

		if (high - low < 2)
			return;

		int mid = (low + high) / 2;

		element0 = new node();
		element0->create_segment_tree(low, mid);
		element1 = new node();
		element1->create_segment_tree(mid, high);

		value = element0->value + element1->value;
	}

	void increase(int low, int high, int index)
	{
		if (high - low < 2)
			value += 1;
		else
		{
			int mid = (low + high) / 2;

			if (index < mid)
				element0->increase(low, mid, index);
			else
				element1->increase(mid, high, index);

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

	void clear()
	{
		value = 0;

		if (element0 != nullptr)
			element0->clear();
		if (element1 != nullptr)
			element1->clear();
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	node* segment_tree = new node();
	segment_tree->create_segment_tree(0, 75000);

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int64 r = 0;

		int n;
		cin >> n;

		vector2d p[75000];
		for (int i = 0; i < n; ++i)
			cin >> p[i].x >> p[i].y;

		sort(p, p + n, [](const vector2d& a, const vector2d& b) -> bool { return a.y > b.y; });

		for (int i = 0, c = 0; i < n; ++i)
		{
			if (i + 1 < n && p[i].y == p[i + 1].y)
				p[i].y = c;
			else
				p[i].y = c++;
		}

		sort(p, p + n, [](const vector2d& a, const vector2d& b) -> bool { return a.x == b.x ? a.y < b.y : a.x < b.x; });

		for (int i = 0; i < n; ++i)
		{
			r += segment_tree->find(0, 75000, 0, p[i].y + 1);
			segment_tree->increase(0, 75000, p[i].y);
		}

		cout << r << endl;
		segment_tree->clear();
	}

	delete segment_tree;
	return 0;
}