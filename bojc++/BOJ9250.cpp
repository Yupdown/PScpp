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

		TrieNode* last_nodes[26]{};

		while (!node_queue.empty())
		{
			int size = node_queue.size();
			while (size-- > 0)
			{
				TrieNode* node = node_queue.front();
				node_queue.pop();

				for (int i = 0; i < 26; ++i)
				{
					TrieNode* next_node = node->next_nodes_[i];

					if (next_node == nullptr)
						continue;

					TrieNode* last_node = last_nodes[i];
					if (last_node == nullptr)
						last_node = front_node_;

					next_node->fallback_ = last_node;
					last_nodes[i] = next_node;

					node_queue.push(next_node);
				}
			}
		}
	}

	int Function(const char* string)
	{
		char* ptr = (char*)string;
		TrieNode* current_node = front_node_;

		for (char* ptr = (char*)string; *ptr != 0; ++ptr)
		{
			TrieNode* next_node = current_node->next_nodes_[*ptr - 97];

			if (next_node == nullptr)
			{
				if (current_node->fallback_ != nullptr)
				{
					current_node = current_node->fallback_;
					--ptr;
				}
			}
			else
				current_node = next_node;

			if (current_node->terminal_)
				return 1;
		}

		return 0;
	}
};

string* s[1000];
char buffer[10001];

int main()
{
	FASTIO();
	
	int n, q;
	Trie* trie = new Trie();

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		s[i] = new string{};
		cin >> *s[i];
	}

	sort(s, s + n, [](const string* a, const string* b) -> bool { return a->length() < b->length(); });

	for (int i = 0; i < n; ++i)
	{
		const char* c_str = (*s[i]).c_str();

		if (trie->Function(c_str))
			continue;

		trie->Insert(c_str);
		trie->BuildFallback();
	}

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> buffer;
		cout << (trie->Function(buffer) ? "YES" : "NO") << '\n';
	}

	delete trie;
}