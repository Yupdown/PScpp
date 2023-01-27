#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int recursion(const char* s, int l, int r, int* c)
{
    ++(*c);
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    return recursion(s, l + 1, r - 1, c);
}

int isPalindrome(const char* s, int* c)
{
    return recursion(s, 0, strlen(s) - 1, c);
}

char s[1024];

int main()
{
	FASTIO();

    int n;
    cin >> n;

    while (n-- > 0)
    {
        int c = 0;
        cin >> s;
        cout << isPalindrome(s, &c) << " " << c << "\n";
    }
}