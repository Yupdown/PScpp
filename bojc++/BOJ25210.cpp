#include <iostream>
#include <cmath>

using namespace std;
typedef long long int64;

int main()
{
	int64 cnt = 0L;
	struct {
		int x1, x2;
		int y1, y2;
	} rect[4];

	for (int i = 0; i < 4; ++i)
		cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;

	for (int l = 2; l <= 200000; ++l)
	{
		int dx = min(min(rect[0].x2, rect[1].x1 + l), min(rect[3].x2, rect[2].x1 + l)) - max(max(rect[0].x1, rect[1].x2 + l), max(rect[3].x1, rect[2].x2 + l));
		int dy = min(min(rect[0].y2, rect[3].y1 + l), min(rect[1].y2, rect[2].y1 + l)) - max(max(rect[0].y1, rect[3].y2 + l), max(rect[1].y1, rect[2].y2 + l));
		cnt += max<int64>(dx + 1, 0) * max<int64>(dy + 1, 0);
	}

	cout << cnt << '\n';
	return 0;
}