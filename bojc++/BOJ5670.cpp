#include <iostream>
#include <map>

using namespace std;

class trie
{
private:
	class trie_node
	{
	private:
		bool terminal = false;
		map<char, trie_node*> next;

	public:
		void insert(const char* string)
		{
			if (*string == 0)
			{
				terminal = true;
				return;
			}

			auto iter = next.find(*string);
			trie_node* next_node;

			if (iter != next.end())
				next_node = iter->second;
			else
			{
				next_node = new trie_node();
				next.insert(make_pair(*string, next_node));
			}

			next_node->insert(string + 1);
		}

		void clear()
		{
			for (auto iter = next.begin(); iter != next.end(); ++iter)
			{
				iter->second->clear();
				delete iter->second;
			}
			next.clear();
		}

		int function(int cnt, bool root = false)
		{
			int result = 0;

			if (terminal)
				result += cnt;

			if (next.size() > 1 || terminal || root)
				++cnt;

			for (auto iter = next.begin(); iter != next.end(); ++iter)
				result += iter->second->function(cnt);

			return result;
		}
	};
	trie_node* front;

public:
	trie()
	{
		front = new trie_node();
	}

	void insert(const char* string)
	{
		front->insert(string);
	}

	void clear()
	{
		front->clear();
	}

	int function()
	{
		return front->function(0, true);
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	int n;
	char buffer[128];
	trie t;

	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> buffer;
			t.insert(buffer);
		}

		cout << (double)t.function() / n << '\n';
		t.clear();
	}

	return 0;
}