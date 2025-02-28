#include <iostream>
#include <map>

using namespace std;

class trie
{
private:
	class trie_node
	{
	private:
		bool end;
		map<char, trie_node*> next;

	public:
		trie_node()
		{
			end = false;
		}

		int contains(char* string, int count)
		{
			if (end)
				return count - 1;
			if (*string == 0)
				return 0;

			auto next_iter = next.find(*string);

			if (next_iter != next.end())
				return next_iter->second->contains(string + 1, count + 1);
			else
				return 0;
		}

		void insert(char* string)
		{
			if (*string == 0)
			{
				end = true;
				return;
			}

			auto next_iter = next.find(*string);
			trie_node* next_node;

			if (next_iter != next.end())
				next_node = next_iter->second;
			else
			{
				next_node = new trie_node();
				next.insert(make_pair(*string, next_node));
			}

			next_node->insert(string + 1);
		}
	};
	trie_node* front;

public:
	trie()
	{
		front = new trie_node();
	}

	int contains(char* string)
	{
		return front->contains(string, 0);
	}

	void insert(char* string)
	{
		front->insert(string);
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	trie croatia_trie;
	croatia_trie.insert("c=");
	croatia_trie.insert("c-");
	croatia_trie.insert("dz=");
	croatia_trie.insert("d-");
	croatia_trie.insert("lj");
	croatia_trie.insert("nj");
	croatia_trie.insert("s=");
	croatia_trie.insert("z=");

	int count = 0;
	char str[128], * ptr = str;
	cin >> str;

	while (*ptr != 0)
	{
		int cnt = croatia_trie.contains(ptr);
		ptr += cnt + 1;
		count++;
	}

	cout << count << endl;
	return 0;
}