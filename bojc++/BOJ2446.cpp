#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);

    for (i = 0; i < n * 2 - 1; ++i)
    {
        for (j = 0; j < n + abs(i + 1 - n); ++j)
            printf(abs(i + 1 - n) >= abs(j + 1 - n) ? "*" : " ");
        printf("\n");
    }
    return 0;
}