#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class Trie
{
private:
	class TrieNode
	{
	public:
		int terminal_ = false;
		TrieNode* fallback_ = nullptr;
		TrieNode* next_nodes_[128]{};

	public:
		~TrieNode()
		{
			for (TrieNode* next_node : next_nodes_)
				delete next_node;
		}

		void Insert(const char* string)
		{
			if (*string == 0)
			{
				terminal_ = true;
				return;
			}

			if (next_nodes_[*string] == nullptr)
				next_nodes_[*string] = new TrieNode();

			next_nodes_[*string]->Insert(string + 1);
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

			for (int i = 0; i < 128; ++i)
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

	int Function(const char* string)
	{
		int result = 0;
		TrieNode* current_node = front_node_;

		for (char* ptr = const_cast<char*>(string); *ptr != 0; ++ptr)
		{
			while (current_node != front_node_ && current_node->next_nodes_[*ptr] == nullptr)
				current_node = current_node->fallback_;

			if (current_node->next_nodes_[*ptr] != nullptr)
				current_node = current_node->next_nodes_[*ptr];

			if (current_node->terminal_)
			{
				++result;
				current_node = front_node_;
			}
		}

		return result;
	}
};

char buffer[128];

int main()
{
	FASTIO();

	int n, m;
	Trie* trie;

	while (true)
	{
		cin >> n >> m;
		if (!n && !m)
			break;

		int r = 0;
		trie = new Trie();

		for (int i = 0; i < n; ++i)
		{
			cin >> buffer;
			trie->Insert(buffer);
		}

		trie->BuildFallback();
		cin.ignore();

		for (int i = 0; i < m; ++i)
		{
			cin.getline(buffer, sizeof(buffer));
			r += trie->Function(buffer);
		}

		cout << r << '\n';
		delete trie;
	}
}