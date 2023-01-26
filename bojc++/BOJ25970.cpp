#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class trie
{
private:
	class trie_node
	{
	private:
		bool terminal = false;
		trie_node* element0;
		trie_node* element1;

	public:
		void insert(const char* string)
		{
			if (*string == 0)
			{
				terminal = true;
				return;
			}

			trie_node*& next_node = *string == '0' ? element0 : element1;

			if (next_node == nullptr)
				next_node = new trie_node();

			next_node->insert(string + 1);
		}

		int contains(const char* string)
		{
			if (*string == 0)
				return terminal;

			trie_node*& next_node = *string == '0' ? element0 : element1;
			if (next_node == nullptr)
				return terminal;

			return terminal + next_node->contains(string + 1);
		}

		void clear()
		{
			element0->clear();
			delete element0;
			element1->clear();
			delete element1;
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

	int contains(const char* string)
	{
		return front->contains(string);
	}

	void clear()
	{
		front->clear();
	}
};

trie trie_low, trie_high;
char buffer[256];

int main()
{
	FASTIO();

	int b, n;
	cin >> b;
	for (int i = 0; i < b; ++i) {
		cin >> buffer;
		trie_low.insert(buffer);
	}
	for (int i = 0; i < b; ++i) {
		cin >> buffer;
		trie_high.insert(buffer);
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int c = 0;
		cin >> buffer;
		for (char* ptr = buffer; *ptr != 0; ++ptr)
			c += trie_low.contains(ptr) - trie_high.contains(ptr);
		if (c == 0)
			cout << "GOOD";
		else if (c > 0)
			cout << "HIGH " << c;
		else
			cout << "LOW " << -c;
		cout << '\n';
	}
}