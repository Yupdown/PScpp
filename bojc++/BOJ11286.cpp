#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct absolute_greater
{
	bool operator()(const int& a, const int& b)
	{
		int aa = abs(a);
		int ab = abs(b);
		return aa == ab ? a > b : aa > ab;
	}
};

int main()
{
	priority_queue<int, vector<int>, absolute_greater> q;

	int n;
	scanf("%d", &n);

	while (n-- > 0)
	{
		int v;
		scanf("%d", &v);

		if (v != 0)
			q.push(v);
		else
		{
			if (q.size() > 0)
			{
				v = q.top();
				q.pop();
			}
			printf("%d\n", v);
		}
	}

	return 0;
}