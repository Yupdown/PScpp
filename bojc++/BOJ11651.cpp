#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);

	pair<int, int> points[100000];
	for (int i = 0; i < n; i++)
		scanf("%d %d", &points[i].first, &points[i].second);

	sort(points, points + n, [](const pair<int, int>& a, const pair<int, int>& b) -> bool {return a.second != b.second ? a.second < b.second : a.first < b.first; });

	for (int i = 0; i < n; i++)
		printf("%d %d\n", points[i].first, points[i].second);

	return 0;
}