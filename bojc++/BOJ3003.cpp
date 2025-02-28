#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 6; ++i)
    {
        int v;
        cin >> v;
        switch (i)
        {
        case 0:
        case 1:
            v = 1 - v;
            break;
        case 5:
            v = 8 - v;
            break;
        default:
            v = 2 - v;
            break;
        }
        cout << v << ' ';
    }
}