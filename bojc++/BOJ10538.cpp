#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class Trie
{
private:
	class TrieNode
	{
	public:
		set<int>* terminal_;
		int fallback_;
		int next_nodes_[2];

	public:
		TrieNode()
		{
			Initialize();
		}

		~TrieNode()
		{
			delete terminal_;
		}

		void Initialize()
		{
			terminal_ = nullptr;
			fallback_ = 0;
			memset(next_nodes_, 0, sizeof(next_nodes_));
		}

		void Insert(Trie& trie, const char* string, int value)
		{
			if (*string == 0)
			{
				if (terminal_ == nullptr)
					terminal_ = new set<int>();
				terminal_->insert(value);
				return;
			}

			int index = *string == 'o';

			if (next_nodes_[index] == 0)
				next_nodes_[index] = ++trie.count_;

			trie.node_cache_[next_nodes_[index]].Insert(trie, string + 1, value);
		}
	};

	TrieNode node_cache_[8'192'000];
	int count_;

public:
	Trie()
	{
		count_ = 0;
	}

	void Insert(const char* string, int value)
	{
		node_cache_[0].Insert(*this, string, value);
	}

	void BuildFallback()
	{
		queue<int> node_queue;
		node_queue.push(0);

		while (!node_queue.empty())
		{
			int node = node_queue.front();
			node_queue.pop();

			for (int i = 0; i < 2; ++i)
			{
				int next_node = node_cache_[node].next_nodes_[i];

				if (next_node == 0)
					continue;

				if (node == 0)
					node_cache_[next_node].fallback_ = 0;
				else
				{
					int target_node = node_cache_[node].fallback_;

					while (target_node != 0 && node_cache_[target_node].next_nodes_[i] == 0)
						target_node = node_cache_[target_node].fallback_;

					if (node_cache_[target_node].next_nodes_[i] != 0)
						target_node = node_cache_[target_node].next_nodes_[i];

					node_cache_[next_node].fallback_ = target_node;
				}

				node_queue.push(next_node);
			}
		}
	}

	void Function(const char* string, set<int>* out[2048][2048], int index)
	{
		int current_node = 0;

		for (char* ptr = const_cast<char*>(string); *ptr != 0; ++ptr)
		{
			int next_index = *ptr == 'o';

			while (current_node != 0 && !node_cache_[current_node].next_nodes_[next_index])
				current_node = node_cache_[current_node].fallback_;

			if (node_cache_[current_node].next_nodes_[next_index])
				current_node = node_cache_[current_node].next_nodes_[next_index];

			if (node_cache_[current_node].terminal_ != nullptr)
				out[index][ptr - string] = node_cache_[current_node].terminal_;
		}
	}

	void Clear()
	{
		for (int i = 0; i < count_ + 1; ++i)
			node_cache_[i].Initialize();
		count_ = 0;
	}
};

char buffer[2048];
set<int>* row_set[2048][2048];

Trie trie;

int main()
{
	FASTIO();

	int hp, wp, hm, wm;
	cin >> hp >> wp >> hm >> wm;

	for (int i = 0; i < hp; ++i)
	{
		cin >> buffer;
		trie.Insert(buffer, i);
	}

	trie.BuildFallback();

	for (int i = 0; i < hm; ++i)
	{
		cin >> buffer;
		trie.Function(buffer, row_set, i);
	}

	cout << endl;
}