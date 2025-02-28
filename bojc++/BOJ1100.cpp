#include <iostream>

using namespace std;

int main()
{
    int r = 0;
    char buffer[10];

    for (int i = 0; i < 8; ++i)
    {
        cin >> buffer;
        for (int j = 0; j < 8; ++j)
            r += buffer[j] == 'F' && !((i + j) & 1);
    }
    cout << r;
}