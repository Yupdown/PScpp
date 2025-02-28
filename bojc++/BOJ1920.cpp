#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	int n, m;
	scanf("%d", &n);
	while (n-- > 0)
	{
		int value;
		scanf("%d", &value);
		s.insert(value);
	}

	scanf("%d", &m);
	while (m-- > 0)
	{
		int value;
		scanf("%d", &value);
		printf("%d\n", s.find(value) != s.end());
	}

	return 0;
}