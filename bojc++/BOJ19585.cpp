#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define SIZEOF_CACHE 4000000

using namespace std;

class trie
{
private:
	class trie_node
	{
	private:
		bool terminal = false;
		int next[26] = { 0 };

	public:
		void insert(const char* string, vector<trie_node>& container)
		{
			if (*string == 0)
			{
				terminal = true;
				return;
			}

			int index = *string - 'a';
			int next_node;
			if (next[index])
				next_node = next[index];
			else
			{
				next_node = container.size();
				container.push_back(trie_node());
				next[index] = next_node;
			}

			container[next_node].insert(string + 1, container);
		}

		void contains(const char* string, int* output, vector<trie_node>& container, int c)
		{
			if (terminal)
				output[c] = 1;

			if (*(string + c) == 0)
				return;

			int index = *(string + c) - 'a';
			if (next[index])
				container[next[index]].contains(string, output, container, c + 1);
		}
	};
	vector<trie_node>* cache;

public:
	trie()
	{
		cache = new vector<trie_node>();
		cache->reserve(SIZEOF_CACHE);
		cache->push_back(trie_node());
	}

	void contains(const char* string, int* output)
	{
		(*cache)[0].contains(string, output, *cache, 0);
	}

	void insert(const char* string)
	{
		(*cache)[0].insert(string, *cache);
	}
};

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int c, n, q;
	string str;

	trie color;
	trie nickname;

	cin >> c >> n;
	for (int i = 0; i < c; i++)
	{
		cin >> str;
		color.insert(str.c_str());
	}
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		reverse(str.begin(), str.end());
		nickname.insert(str.c_str());
	}

	int resultA[2048];
	int resultB[2048];

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		memset(resultA, 0, sizeof(resultA));
		memset(resultB, 0, sizeof(resultB));

		cin >> str;

		color.contains(str.c_str(), resultA);
		reverse(str.begin(), str.end());
		nickname.contains(str.c_str(), resultB);

		bool result = false;
		for (int i = 0; i < str.size() + 1 && !result; i++)
		{
			if (resultA[i] && resultB[str.size() - i])
				result = true;
		}

		cout << (result ? "Yes" : "No") << endl;
	}

	return 0;
}