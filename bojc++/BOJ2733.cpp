#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class program
{
public:
	bool compile(const vector<string>& input)
	{
		inst.clear();
		addr.clear();
		stack<int> memo;
		for (const auto& s : input)
		{
			for (const auto& c : s)
			{
				if (c == '%')
					break;
				switch (c)
				{
				case '>':
				case '<':
				case '+':
				case '-':
				case '.':
					inst.emplace_back(c);
					addr.emplace_back();
					break;
				case '[':
					memo.push(inst.size());
					inst.emplace_back(c);
					addr.emplace_back();
					break;
				case ']':
					if (memo.empty())
						return false;
					addr[memo.top()] = inst.size();
					inst.emplace_back(c);
					addr.emplace_back(memo.top());
					memo.pop();
					break;
				}
			}
		}
		return memo.empty();
	}

	string run()
	{
		string ret;
		static char data[0x8000];
		int ptr = 0;

		memset(data, 0, sizeof(data));

		int len = inst.size();
		for (int i = 0; i < len; ++i)
		{
			switch (inst[i])
			{
			case '>':
				ptr = (ptr + 0x0001) % 0x8000;
				break;
			case '<':
				ptr = (ptr + 0x7FFF) % 0x8000;
				break;
			case '+':
				data[ptr] = (data[ptr] + 0x0001) % 0x0100;
				break;
			case '-':
				data[ptr] = (data[ptr] + 0x00FF) % 0x0100;
				break;
			case '.':
				ret.push_back(data[ptr]);
				break;
			case '[':
				if (!data[ptr])
					i = addr[i];
				break;
			case ']':
				if (data[ptr])
					i = addr[i];
				break;
			}
		}
		return ret;
	}

private:
	vector<char> inst;
	vector<int> addr;
};

int main()
{
	FASTIO();
	
	int t;
	cin >> t;
	program p;
	for (int i = 0; i < t; ++i)
	{
		vector<string> sv;
		do
			getline(cin, sv.emplace_back());
		while (sv.back() != "end");
		cout << "PROGRAM #" << i + 1 << ":\n";
		if (p.compile(sv))
			cout << p.run() << "\n";
		else
			cout << "COMPILE ERROR\n";
	}
}