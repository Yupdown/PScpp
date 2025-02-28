#include <iostream>

using namespace std;

int main()
{
    int a[30]{};

    for (int i = 0; i < 28; ++i)
    {
        int v;
        cin >> v;
        a[v - 1] = 1;
    }

    for (int i = 0; i < 30; ++i)
    {
        if (!a[i])
            cout << i + 1 << endl;
    }
}