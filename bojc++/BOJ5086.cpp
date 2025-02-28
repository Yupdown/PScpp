#include <iostream>
using namespace std;

int main()
{
    int a, b;

    while (true)
    {
        cin >> a >> b;
        if (!(a > 0 && b > 0))
            break;

        if (!(b % a))
            cout << "factor\n";
        else if (!(a % b))
            cout << "multiple\n";
        else
            cout << "neither\n";
    }
}