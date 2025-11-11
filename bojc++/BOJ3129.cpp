#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
string message, hint;

vector<int> verdict(int slice, int pos)
{
	vector<int> ret;
	for (int i = 0; i < slice; ++i)
	{
		vector<int> v;
		for (int j = i; j < static_cast<int>(message.size()); j += slice)
		{
			if (j >= pos && j < pos + static_cast<int>(hint.size()))
				v.emplace_back((static_cast<int>(hint[j - pos]) - message[j] + 26) % 26);
		}
		for (int c : v)
		{
			if (c != v[0])
				return {};
		}
		ret.emplace_back(v[0]);
	}
	return ret;
}

int main()
{
	FASTIO();

	cin >> message >> hint;
	for (int slice = 1; slice * 2 <= static_cast<int>(hint.size()); ++slice)
	{
		for (int pos = 0; pos <= static_cast<int>(message.size() - hint.size()); ++pos)
		{
			auto key = verdict(slice, pos);
			if (key.size() > 0)
			{
				for (int i = 0; i < static_cast<int>(message.size()); ++i)
					message[i] = (message[i] + key[i % slice] - 'a') % 26 + 'a';
				cout << message;
				return 0;
			}
		}
	}
}