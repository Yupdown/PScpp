#include <iostream>

using namespace std;

int powerof(int x, int n)
{
    int c = 0;
    while (x >= n)
    {
        x /= n;
        c += x;
    }

    return c;
}

int main()
{
    int n, m;

    cin >> n >> m;

    int count2 = powerof(n, 2) - powerof(n - m, 2) - powerof(m, 2);
    int count5 = powerof(n, 5) - powerof(n - m, 5) - powerof(m, 5);

    cout << (count2 < count5 ? count2 : count5) << endl;
    return 0;
}