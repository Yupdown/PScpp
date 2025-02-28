#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int get_result(int* histogram, int n)
{
	int result = 0;
	stack<int> rectangles;

	rectangles.push(-1);
	for (int i = 0; i < n + 1; i++)
	{
		while (!rectangles.empty())
		{
			int top = rectangles.top();
			if ((top >= 0 ? histogram[top] : 0) <= (i < n ? histogram[i] : 0))
				break;

			rectangles.pop();
			result = max(result, (i - rectangles.top() - 1) * histogram[top]);
		}

		rectangles.push(i);
	}

	return result;
}

int main()
{
	int histogram[100000];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> histogram[i];

	cout << get_result(histogram, n) << endl;
	return 0;
}