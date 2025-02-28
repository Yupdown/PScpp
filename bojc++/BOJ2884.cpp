#include <stdio.h>

int main()
{
    int h, m, r;
    scanf("%d %d", &h, &m);
    r = (h * 60 + m - 45);
    r = r < 0 ? r + 1440 : r;
    printf("%d %d", r / 60, r % 60);
    return 0;
}