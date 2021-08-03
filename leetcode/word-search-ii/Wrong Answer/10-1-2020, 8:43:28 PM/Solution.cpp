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
	void helper(std::vector<std::vector<char>> &board, TrieNode* root, std::vector<std::string> &vecFoundWords,int x,int y){
		std::vector<int> xOffsets{0,0,1,-1};
		std::vector<int> yOffsets{-1,1,0,0};
		auto letter = board[x][y];
		board[y][x] = '-';
		if (root->word != ""){
            vecFoundWords.push_back(root->word);
            root->word = "";
        }
			

		for (auto t = 0; t < 4; ++t){
			auto xx = x + xOffsets[t];
			auto yy = y + yOffsets[t];

			if (xx < 0 || xx > board[0].size()-1 || yy < 0 || yy > board.size()-1)
				continue;
			auto ch = board[yy][xx];
			if (ch == '-')
				continue;
			if (root->children[ch-'a'] ==nullptr)
				continue;
			helper(board,root->children[ch-'a'],vecFoundWords,xx,yy);
		}
		board[y][x]  = letter;
		return;

	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		std::vector<std::string> vecFoundWords;
		auto numRows = board.size();
		if (!numRows) return vecFoundWords;
		auto numCols = board[0].size();

		auto root = new TrieNode();
		for (auto word : words){
			insertWord(root,word);
		}


		for (auto i = 0; i < numRows; ++i){
			for (auto j = 0; j < numCols; ++j){
				helper(board,root,vecFoundWords,i,j);
			}
		}
		return vecFoundWords;
    }
};
