#include <iostream>
#include <math.h>

using namespace std;

class trie
{
private:
	class trie_node
	{
	private:
		bool terminal = false;
		trie_node* next[26] = { 0 };

	public:
		void insert(const char* string)
		{
			if (*string == 0)
			{
				terminal = true;
				return;
			}

			if (!next[*string - 'a'])
				next[*string - 'a'] = new trie_node();

			next[*string - 'a']->insert(string + 1);
		}

		bool contains(const char* string)
		{
			if (*string == 0)
				return terminal;

			if (!next[*string - 'a'])
				return false;

			return next[*string - 'a']->contains(string + 1);
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

	bool contains(const char* string)
	{
		return front->contains(string);
	}
};

int main()
{
	int n, m, r = 0;
	char buffer[512];
	trie dictionary_trie;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;
		dictionary_trie.insert(buffer);
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> buffer;
		if (dictionary_trie.contains(buffer))
			++r;
	}

	cout << r << endl;
	return 0;
}