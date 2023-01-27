#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define SIZEOF_ARRAY(a) (sizeof(a) / sizeof(*(a)))

using namespace std;

class Trie
{
private:
	class TrieNode
	{
	private:
		char* terminal_ = nullptr;
		TrieNode* next_nodes_[26]{};

	public:
		void Insert(const char* string, const char* ptr)
		{
			if (*string == 0)
			{
				terminal_ = (char*)ptr;
				return;
			}

			int index = *string - 65;

			if (next_nodes_[index] == nullptr)
				next_nodes_[index] = new TrieNode();

			next_nodes_[index]->Insert(string + 1, ptr);
		}

		void Function(const char board[16], int p, int bitmask, set<char*>& out)
		{
			TrieNode* next_node = next_nodes_[board[p] - 65];
			if (next_node == nullptr)
				return;

			if (next_node->terminal_ != nullptr && out.find(next_node->terminal_) == out.end())
				out.insert(next_node->terminal_);

			int directions[] = { p - 5, p - 4, p - 3, p - 1, p + 1, p + 3, p + 4, p + 5 };

			for (int i = 0; i < SIZEOF_ARRAY(directions); ++i)
			{
				int next_p = directions[i];

				if (next_p < 0 || next_p >= 16)
					continue;
				if (abs(p % 4 - next_p % 4) > 1)
					continue;
				if (bitmask & (1 << next_p))
					continue;

				next_node->Function(board, next_p, bitmask | (1 << next_p), out);
			}
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

	void Insert(const char* string)
	{
		front_node_->Insert(string, string);
	}

	void Function(const char board[16], int p, set<char*>& out)
	{
		front_node_->Function(board, p, 1 << p, out);
	}
};

char dictionary[300000][9];

int main()
{
	FASTIO();

	int w;
	cin >> w;

	Trie* trie_dictionary = new Trie();
	set<char*>* output = new set<char*>();

	for (int i = 0; i < w; ++i)
	{
		cin >> dictionary[i];
		trie_dictionary->Insert(dictionary[i]);
	}

	int b;
	cin >> b;

	for (int i = 0; i < b; ++i)
	{
		char boggle[20];

		for (int j = 0; j < 16; j += 4)
			cin >> (boggle + j);

		for (int j = 0; j < 16; ++j)
			trie_dictionary->Function(boggle, j, *output);

		int sum = 0;
		char* word_maxlen = *output->begin();

		for (auto iter : *output)
		{
			int len = strlen(iter);

			switch (len)
			{
			case 8:
				sum += 11;
				break;
			case 7:
				sum += 5;
				break;
			case 6:
				sum += 3;
				break;
			case 5:
				sum += 2;
				break;
			case 4:
			case 3:
				sum += 1;
				break;
			}

			int maxlen = strlen(word_maxlen);
			word_maxlen = (len == maxlen ? strcmp(iter, word_maxlen) < 0 : len > maxlen) ? iter : word_maxlen;
		}

		cout << sum << ' ' << word_maxlen << ' ' << output->size() << '\n';
		output->clear();
	}
}