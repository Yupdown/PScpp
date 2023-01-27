#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class Trie
{
private:
	class TrieNode
	{
	public:
		bool terminal_;
		int fallback_;
		int next_nodes_[4];

	public:
		TrieNode()
		{
			Initialize();
		}

		void Initialize()
		{
			terminal_ = false;
			fallback_ = 0;
			memset(next_nodes_, 0, sizeof(next_nodes_));
		}

		void Insert(Trie& trie, const char* string)
		{
			if (*string == 0)
			{
				terminal_ = true;
				return;
			}

			int index = *string - 1;

			if (next_nodes_[index] == 0)
				next_nodes_[index] = ++trie.count_;

			trie.node_cache_[next_nodes_[index]].Insert(trie, string + 1);
		}
	};

	TrieNode node_cache_[8'192'000];
	int count_;

public:
	Trie()
	{
		count_ = 0;
	}

	void Insert(const char* string)
	{
		node_cache_[0].Insert(*this, string);
	}

	void BuildFallback()
	{
		queue<int> node_queue;
		node_queue.push(0);

		while (!node_queue.empty())
		{
			int node = node_queue.front();
			node_queue.pop();

			for (int i = 0; i < 4; ++i)
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

				if (node_cache_[node_cache_[next_node].fallback_].terminal_)
					node_cache_[next_node].terminal_ = true;

				node_queue.push(next_node);
			}
		}
	}

	int Function(const char* string)
	{
		int cnt = 0;
		int current_node = 0;

		for (char* ptr = const_cast<char*>(string); *ptr != 0; ++ptr)
		{
			int next_index = *ptr - 1;

			while (current_node != 0 && !node_cache_[current_node].next_nodes_[next_index])
				current_node = node_cache_[current_node].fallback_;

			if (node_cache_[current_node].next_nodes_[next_index])
				current_node = node_cache_[current_node].next_nodes_[next_index];

			cnt += node_cache_[current_node].terminal_;
		}

		return cnt;
	}

	void Clear()
	{
		for (int i = 0; i < count_ + 1; ++i)
			node_cache_[i].Initialize();
		count_ = 0;
	}
};

char dna[1'048'576];
char marker[128];
char marker_temp[128];

void ProcessString(char* str)
{
	for (char* ptr = str; *ptr != 0; ++ptr)
	{
		switch (*ptr)
		{
		case 'A':
			*ptr = 1;
			break;
		case 'C':
			*ptr = 2;
			break;
		case 'G':
			*ptr = 3;
			break;
		case 'T':
			*ptr = 4;
			break;
		}
	}
}

Trie trie;

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		int n, m;
		cin >> n >> m;

		cin >> dna;
		cin >> marker;

		ProcessString(dna);
		ProcessString(marker);

		trie.Insert(marker);
		for (int i = 0; i < m; ++i)
		{
			for (int j = i + 2; j <= m; ++j)
			{
				copy(begin(marker), end(marker), marker_temp);
				reverse(begin(marker_temp) + i, begin(marker_temp) + j);

				trie.Insert(marker_temp);
			}
		}

		trie.BuildFallback();
		cout << trie.Function(dna) << endl;

		trie.Clear();
	}
}