#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> q;

	int n;
	scanf("%d", &n);

	while (n-- > 0)
	{
		int v;
		scanf("%d", &v);

		if (v > 0)
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