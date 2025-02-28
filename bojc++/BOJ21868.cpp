#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int en, ed;
	int fm, fb;
	int x0;

	cin >> en >> ed >> fm >> fb >> x0;

	cout << fm * x0 + fb << endl;
	cout << (fm != 0 ? en : 0) << ' ' << abs(ed * fm) << endl;

	return 0;
}