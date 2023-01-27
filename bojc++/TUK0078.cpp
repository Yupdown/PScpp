#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class Trie
{
private:
	class TrieNode
	{
	public:
		int terminal_ = 0;
		bool used_ = false;
		TrieNode* next_nodes_[26]{};

	public:
		~TrieNode()
		{
			for (TrieNode* next_node : next_nodes_)
				delete next_node;
		}

		int Insert(char* string, bool flag)
		{
			if (*string == 0)
				return ++terminal_;

			int alphabet = *string - 'a';

			if (next_nodes_[alphabet] == nullptr)
			{
				next_nodes_[alphabet] = new TrieNode();
				flag = !(flag || next_nodes_[alphabet]->used_);
			}

			int r = next_nodes_[alphabet]->Insert(string + 1, flag);

			if (flag)
			{
				next_nodes_[alphabet]->used_ = true;
				*(string + 1) = 0;
				r = 0;
			}

			return r;
		}
	};
	TrieNode* front_node_;

public:
	Trie()
	{
		front_node_ = new TrieNode();
	}

	~Trie()
	{
		delete front_node_;
	}

	int Insert(char* string)
	{
		return front_node_->Insert(string, false);
	}
};

Trie trie;

int main()
{
	FASTIO();

	char buffer[16];

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;
		int value = trie.Insert(buffer);
		cout << buffer;
		if (value > 1)
			cout << value;
		cout << "\n";
	}
}