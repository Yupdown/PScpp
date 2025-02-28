#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double ax, ay, az, bx, by, bz, cx, cy, cz, result = 0.0;
    cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;

    if (cz <= min(az, bz))
        result = 0.0;
    else if (cz <= max(az, bz))
    {
        bool c1 = ax == bx;
        bool c2 = ay == by;

        if (c1 && c2)
            result = 0.0;
        else if (c1)
            result = cx == ax ? 0.0 : -1.0;
        else if (c2)
            result = cy == ay ? 0.0 : -1.0;
        else
            result = -1.0;
    }
    else
    {
        double dx = cx + (ax - cx) * (cz / (cz - az));
        double dy = cy + (ay - cy) * (cz / (cz - az));
        double ex = cx + (ax - cx) * (cz / (cz - bz));
        double ey = cy + (ay - cy) * (cz / (cz - bz));
        double fx = cx + (bx - cx) * (cz / (cz - az));
        double fy = cy + (by - cy) * (cz / (cz - az));
        double gx = cx + (bx - cx) * (cz / (cz - bz));
        double gy = cy + (by - cy) * (cz / (cz - bz));

        double hx = max(abs(dx - gx), abs(ex - fx));
        double hy = max(abs(dy - gy), abs(ey - fy));
        double ix = abs(dx - fx);
        double iy = abs(dy - fy);
        double jx = abs(ex - gx);
        double jy = abs(ey - gy);
        hx = max(hx, max(ix, jx));
        hy = max(hy, max(iy, jy));

        result = hx * hy - ((hx - ix) * (hy - jy) + (hx - jx) * (hy - iy)) * 0.5;
    }

    cout.precision(12);
    cout << result << endl;
    return 0;
}