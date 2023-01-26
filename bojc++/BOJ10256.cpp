#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

class Trie
{
private:
	class TrieNode
	{
	public:
		bool terminal_ = false;
		TrieNode* fallback_ = nullptr;
		TrieNode* next_nodes_[4]{};

	public:
		void Insert(const char* string)
		{
			if (*string == 0)
			{
				terminal_ = true;
				return;
			}

			int index = *string - 1;

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

			for (int i = 0; i < 4; ++i)
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
		int cnt = 0;

		char* ptr = (char*)string;
		TrieNode* current_node = front_node_;

		while (*ptr != 0)
		{
			TrieNode* next_node = current_node->next_nodes_[*ptr - 1];

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
				++cnt;
		}

		return cnt;
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

void ProcessMarker(char* src, char* dst, int from, int to)
{
	for (int i = 0; src[i] != 0; ++i)
		dst[i] = src[i];

	for (int i = from; i <= to; ++i)
		dst[i] = src[to - i + from];
}

int main()
{
	FASTIO();

	int t;
	cin >> t;

	while (t-- > 0)
	{
		Trie* trie = new Trie();

		int n, m;
		cin >> n >> m;

		cin >> dna;
		cin >> marker;

		ProcessString(dna);
		ProcessString(marker);

		for (int i = 0; i < m; ++i)
		{
			for (int j = i + 1; j < m; ++j)
			{
				ProcessMarker(marker, marker_temp, i, j);
				trie->Insert(marker_temp);
			}
		}

		trie->BuildFallback();
		cout << trie->Process(dna) << endl;
		
		delete trie;
	}
}