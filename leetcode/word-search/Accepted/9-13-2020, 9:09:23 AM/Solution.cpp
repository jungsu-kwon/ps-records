// https://leetcode.com/problems/word-search

class Solution {
private : 
	//std::vector<std::pair<int,int>> 
	int nRows = 0 ;
	int nCols = 0 ;
	bool isWithinBound(int x , int y){
		if (x < nRows && x  >= 0 && y >= 0 && y < nCols)
			return true;
		return false;
	}
	bool search(std::vector<std::vector<char>>& board, std::string &word, int start, int x, int y)
	{
        if (start == word.size())
			return true;
		if (!isWithinBound(x,y))
			return false;


		auto curLocChar = board[x][y];
		if (curLocChar != word[start])
			return false;

		board[x][y] = '0';
		auto bFound = (search(board,word,start+1,x+1,y)||
					   search(board,word,start+1,x-1,y)||
					   search(board,word,start+1,x,y-1)||
					   search(board,word,start+1,x,y+1));

		if (bFound)
			return true;
		board[x][y] = curLocChar;
		return false;
	}
	 
public:
	bool exist(vector<vector<char>>& board, string word) {
		nRows = board.size();
		if (nRows == 0 )
			return false;
		nCols = board[0].size();
		if (nCols == 0 )
			return false;

		for (auto i = 0; i < nRows; ++i){
			for (auto j = 0; j < nCols; ++j){
				if (search(board,word,0,i,j))
					return true;
			}
		}
		return false;
	}
};


