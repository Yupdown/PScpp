#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double d, h, w, k;
	cin >> d >> h >> w;
	k = sqrt(d * d / (w * w + h * h));
	cout << (int)(k * h) << ' ' << (int)(k * w) << endl;
	return 0;
}