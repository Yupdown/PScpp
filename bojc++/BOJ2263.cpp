#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int inorder[100000];
int postorder[100000];

void Function(int i_from, int i_to, int p_from, int p_to)
{
	int value = postorder[p_to - 1];
	int imid = find(inorder + i_from, inorder + i_to, value) - inorder;
	int pmid = p_from + imid - i_from;

	cout << value << " ";

	if (i_from < imid)
		Function(i_from, imid, p_from, pmid);
	if (imid + 1 < i_to)
		Function(imid + 1, i_to, pmid, p_to - 1);
}

int main()
{
	FASTIO();

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> inorder[i];
	for (int i = 0; i < n; ++i)
		cin >> postorder[i];

	Function(0, n, 0, n);
	cout << "\n";
}