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
		TrieNode* fallback_ = nullptr;
		TrieNode* next_nodes_[2]{};

	public:
		~TrieNode()
		{
			for (TrieNode* next_node : next_nodes_)
				delete next_node;
		}

		void Insert(const char* string, int value)
		{
			if (*string == 0)
			{
				terminal_ = value;
				return;
			}

			int index = *string == 'o';

			if (next_nodes_[index] == nullptr)
				next_nodes_[index] = new TrieNode();

			next_nodes_[index]->Insert(string + 1, value);
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

	void Insert(const char* string, int value)
	{
		front_node_->Insert(string, value);
	}

	void BuildFallback()
	{
		queue<TrieNode*> node_queue;
		node_queue.push(front_node_);

		while (!node_queue.empty())
		{
			TrieNode* node = node_queue.front();
			node_queue.pop();

			for (int i = 0; i < 2; ++i)
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

				if (next_node->fallback_->terminal_ > 0)
					next_node->terminal_ = next_node->fallback_->terminal_;

				node_queue.push(next_node);
			}
		}
	}

	int Find(const char* string)
	{
		TrieNode* current_node = front_node_;

		for (char* ptr = const_cast<char*>(string); *ptr != 0; ++ptr)
		{
			int index = *ptr == 'o';

			if (current_node->next_nodes_[index] != nullptr)
				current_node = current_node->next_nodes_[index];
			else
				return 0;

			if (current_node->terminal_ > 0)
				return current_node->terminal_;
		}

		return 0;
	}

	int Process(const char* string, int* out)
	{
		int cnt = 0;

		TrieNode* current_node = front_node_;

		for (char* ptr = const_cast<char*>(string); *ptr != 0; ++ptr)
		{
			int index = *ptr == 'o';

			while (current_node != front_node_ && current_node->next_nodes_[index] == nullptr)
				current_node = current_node->fallback_;

			if (current_node->next_nodes_[index] != nullptr)
				current_node = current_node->next_nodes_[index];

			if (current_node->terminal_ > 0)
				out[ptr - string] = current_node->terminal_;
		}

		return cnt;
	}
};

char buffer[2048];
int pattern[2048];
int pattern_board[2048][2048];
int board_buffer[2048];
int fallback[2048];
Trie trie;

void BuildFallback(const int* pattern, int* output, int size)
{
	for (int i = 1, j = 0; i < size; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = output[j - 1];

		if (pattern[i] == pattern[j])
			output[i] = ++j;
	}
}

int KmpSearch(const int* input, const int* pattern, const int* fallback, int size, int pattern_size)
{
	int cnt = 0;

	for (int i = 0, j = 0; i < size; ++i)
	{
		while (j > 0 && input[i] != pattern[j])
			j = fallback[j - 1];

		if (input[i] == pattern[j])
		{
			if (j + 1 < pattern_size)
				++j;
			else
			{
				j = fallback[j];
				++cnt;
			}
		}
	}

	return cnt;
}

int main()
{
	FASTIO();

	int hp, wp, hm, wm;
	cin >> hp >> wp >> hm >> wm;

	int cnt = 0;
	for (int i = 0; i < hp; ++i)
	{
		cin >> buffer;

		pattern[i] = trie.Find(buffer);
		if (!pattern[i])
		{
			trie.Insert(buffer, ++cnt);
			pattern[i] = cnt;
		}
	}

	trie.BuildFallback();
	BuildFallback(pattern, fallback, hp);

	for (int i = 0; i < hm; ++i)
	{
		cin >> buffer;
		trie.Process(buffer, pattern_board[i]);
	}

	int res = 0;
	for (int i = 0; i < wm; ++i)
	{
		for (int j = 0; j < hm; ++j)
			board_buffer[j] = pattern_board[j][i];

		res += KmpSearch(board_buffer, pattern, fallback, hm, hp);
	}

	cout << res << endl;
}