// https://leetcode.com/problems/valid-sudoku

#include <vector>
using namespace std;

class Solution {
private : 
	bool isValidRow(vector<char> &row){
		std::vector<bool> vecExists(9,false);
		for (auto num : row){
			if (num == '.'){
				continue;
			}
			else{
				if (vecExists[num-'0'] == true){
					return false;
				}
				else {
					vecExists[num-'0'] = true;
				}

			}
		}
		return true;
	}
	bool isValidCol(std::vector<std::vector<char>> &board, int colInd){
		std::vector<bool> vecExists(9,false);
		for (auto t = 0 ; t < 9; ++t){
			auto num = board[t][colInd];
			if (num == '.'){
				continue;
			}
			else{
				if (vecExists[num-'0'] == true){
					return false;
				}
				else {
					vecExists[num-'0'] = true;
				}

			}

		}
		return true;
	}

	bool isValidBlock(std::vector<std::vector<char>> &board,int rowInd, int colInd){
		std::vector<bool> vecExists(9,false);
		for (auto i = rowInd; i < rowInd + 3 ; ++i){
			for (auto j = colInd; j < colInd +3; ++j){
				auto num = board[i][j];
				if (num == '.'){
					continue;
				}
				else{
					if (vecExists[num-'0'] == true){
						return false;
					}
					else {
						vecExists[num-'0'] = true;
					}
				}
			}
		}
		return true;
	}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		for (auto i = 0 ; i < 9; ++i){
			if (!isValidRow(board[i])) return false;
			if (!isValidCol(board,i)) return false;
		}
		for (auto i = 0 ; i < 6; i += 3){
			for (auto j = 0 ; j < 6; j+=3){
				if (!isValidBlock(board,i,j)) return false;
			}
		}
		return true;
        
    }
};
