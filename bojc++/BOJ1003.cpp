#include <stdio.h>

int main()
{
    int t, a, b;
    int* n;

    scanf("%d", &t);

    n = new int[t];

    for (int i = 0; i < t; i++)
        scanf("%d", &n[i]);

    for (int i = 0; i < t; i++)
    {
        a = 1, b = 0;

        for (int j = 0; j < n[i]; j++)
        {
            int temp = b;
            b += a;
            a = temp;
        }

        printf("%d %d\n", a, b);
    }

    delete[] n;

    return 0;
}