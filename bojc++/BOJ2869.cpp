#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, v;
    cin >> a >> b >> v;
    v -= a;
    cout << (v > 0 ? (int)ceil((double)v / (a - b)) : 0) + 1 << endl;
    return 0;
}