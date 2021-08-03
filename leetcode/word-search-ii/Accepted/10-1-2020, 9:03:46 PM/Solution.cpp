// https://leetcode.com/problems/word-search-ii

#include <vector>
#include <iostream>
#include <string>
using namespace std;
struct TrieNode{
	std::vector<TrieNode*> children;
	std::string word = "";
	TrieNode(){
		children.resize(26,nullptr);
	}
};
class Solution {
private : 
	int numRows = 0;
	int numCols = 0;
	void insertWord(TrieNode* root, std::string &word)
	{
		TrieNode* curNode = root;
		for (auto ch : word){
			if (curNode->children[ch-'a'] == nullptr){
				curNode->children[ch-'a'] = new TrieNode();
				curNode = curNode->children[ch-'a'];
			}
			else {
				curNode = curNode->children[ch-'a'];
			}
		}
		curNode->word = word;
	}
	void helper(std::vector<std::vector<char>> &board, TrieNode* root, std::vector<std::string> &vecFoundWords,int i,int j){
		if (!root) return ;
		std::vector<int> iOffsets{0,0,1,-1};
		std::vector<int> jOffsets{-1,1,0,0};
		auto letter = board[i][j];
		board[i][j] = '-';
		if (root->word != ""){
			vecFoundWords.push_back(root->word);
			root->word = "";
		}

		for (auto t = 0; t < 4; ++t){
			auto ii = i + iOffsets[t];
			auto jj = j + jOffsets[t];

			if (ii < 0 || ii > numRows - 1 || jj < 0 || jj > numCols-1)
				continue;
			auto ch = board[ii][jj];
			if (ch == '-' || root->children[ch-'a'] == nullptr)
				continue;
			helper(board,root->children[ch-'a'],vecFoundWords,ii,jj);
		}
		board[i][j]  = letter;
		return;

	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		std::vector<std::string> vecFoundWords;
		numRows = board.size();
		if (!numRows) return vecFoundWords;
		numCols = board[0].size();

		auto root = new TrieNode();
		for (auto word : words){
			insertWord(root,word);
		}


		for (auto i = 0; i < numRows; ++i){
			for (auto j = 0; j < numCols; ++j){
				auto letter = board[i][j];
				helper(board,root->children[letter-'a'],vecFoundWords,i,j);
			}
		}
		return vecFoundWords;
    }
};
