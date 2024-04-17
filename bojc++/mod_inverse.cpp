using int64 = long long;

int64 mod_inverse(int64 a, int64 m) {
    int64 m0 = m, t, q;
    int64 x0 = 0, x1 = 1;

    while (a > 1)
    {
        if (m == 0)
            return -1;

        q = a / m;
        t = m;

        m = a % m, a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}