#include <iostream>

using namespace std;

int main()
{
    int n, r = 0;
    cin >> n;

    while (n > 0)
        r += n--;
    cout << r << endl;

    return 0;
}