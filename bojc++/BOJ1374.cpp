#include <iostream>

using namespace std;

int sqr(int x)
{
    return x * x;
}

int main()
{
    int w, h, x, y, p, r = 0;
    cin >> w >> h >> x >> y >> p;

    while (p-- > 0)
    {
        int px, py;
        cin >> px >> py;

        if (px >= x && px <= x + w && py >= y && py <= y + h)
            r++;
        else if (sqr(px - x) + sqr(py - (y + h / 2)) <= sqr(h / 2))
            r++;
        else if (sqr(px - (x + w)) + sqr(py - (y + h / 2)) <= sqr(h / 2))
            r++;
    }

    cout << r << endl;
    return 0;
}