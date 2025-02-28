#include <stdio.h>
#define MIN(a, b) (a) < (b) ? (a) : (b)

int main()
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", MIN(x, MIN(y, MIN(w - x, h - y))));
    return 0;
}