// https://leetcode.com/problems/implement-trie-prefix-tree

using namespace std;
struct TrieNode{
	std::unordered_map<char,TrieNode*> hash;
	bool finish = false;
};
class Trie {
public:
	/** Initialize your data structure here. */
	TrieNode* root;
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		if (!search(word) )
		{
			auto curNode = root;
			for (auto ch : word)
			{
				if (curNode->hash.find(ch) != curNode->hash.end())
					curNode = curNode->hash[ch];
				else
				{
					curNode->hash[ch] = new TrieNode();
					curNode = curNode->hash[ch];
				}
			}
			curNode->finish = true;
		}

	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		auto curNode = root;
		for (auto ch : word)
		{
			if (curNode->hash.find(ch) != curNode->hash.end()){
				curNode = curNode->hash[ch];
			}
			else 
				return false;
		}
		if (curNode->finish)
			return true;
		else 
			return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		auto curNode = root;
		for (auto ch : prefix)
		{
			if (curNode->hash.find(ch) != curNode->hash.end()){
				curNode = curNode->hash[ch];
			}
			else 
				return false;
		}
		return true;

	}
};

