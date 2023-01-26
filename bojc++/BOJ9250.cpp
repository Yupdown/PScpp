#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define SIZEOF_ARRAY(a) (sizeof(a) / sizeof(*(a)))

using namespace std;

class Trie
{
private:
	class TrieNode
	{
	public:
		bool terminal_ = false;
		TrieNode* fallback_ = nullptr;
		TrieNode* next_nodes_[26]{};

	public:
		void Insert(const char* string)
		{
			if (*string == 0)
			{
				terminal_ = true;
				return;
			}

			int index = *string - 97;

			if (next_nodes_[index] == nullptr)
				next_nodes_[index] = new TrieNode();

			next_nodes_[index]->Insert(string + 1);
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
		front_node_->Insert(string);
	}

	void BuildFallback()
	{
		queue<TrieNode*> node_queue;
		node_queue.push(front_node_);

		while (!node_queue.empty())
		{
			TrieNode* node = node_queue.front();
			node_queue.pop();

			for (int i = 0; i < 26; ++i)
			{
				TrieNode* next_node = node->next_nodes_[i];

				if (next_node == nullptr)
					continue;

				if (node == front_node_)
					next_node->fallback_ = front_node_;
				else
				{
					TrieNode* target_node = node->fallback_;

					while (target_node != front_node_ && target_node->next_nodes_[i] == nullptr)
						target_node = target_node->fallback_;

					if (target_node->next_nodes_[i] != nullptr)
						target_node = target_node->next_nodes_[i];

					next_node->fallback_ = target_node;
				}

				if (next_node->fallback_->terminal_)
					next_node->terminal_ = true;

				node_queue.push(next_node);
			}
		}
	}

	int Process(const char* string)
	{
		char* ptr = (char*)string;
		TrieNode* current_node = front_node_;

		while (*ptr != 0)
		{
			TrieNode* next_node = current_node->next_nodes_[*ptr - 97];

			if (next_node == nullptr)
			{
				if (current_node == front_node_)
					++ptr;
				else
					current_node = current_node->fallback_;
			}
			else
			{
				current_node = next_node;
				++ptr;
			}

			if (current_node->terminal_)
				return 1;
		}

		return 0;
	}
};

char buffer[16384];

int main()
{
	FASTIO();

	int n, q;
	Trie* trie = new Trie();

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> buffer;
		trie->Insert(buffer);
	}

	trie->BuildFallback();

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> buffer;
		cout << (trie->Process(buffer) ? "YES" : "NO") << '\n';
	}

	delete trie;
}