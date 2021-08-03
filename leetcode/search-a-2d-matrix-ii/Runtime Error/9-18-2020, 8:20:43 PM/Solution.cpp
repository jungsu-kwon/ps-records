// https://leetcode.com/problems/search-a-2d-matrix-ii

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		auto numRows = matrix.size();
		auto numCols = (matrix.size() == 0 ) ? 0 : matrix[0].size();
		if (numRows == 0 || numCols == 0)
			return false;

		auto maxRowInd = numRows;
		for (auto i = 0; i < numRows; ++i){
			if (matrix[i][0] > target){
				maxRowInd = i;
				break;
			}
		}
		auto maxColInd = numCols;
		for (auto j = 0; j < numCols; ++j){
			if (matrix[0][j] > target){
				maxColInd = j;
				break;
			}
		}


		auto maxColIndTemp = maxColInd;
		for (auto i = 0; i < maxRowInd; ++ i){
			for (auto j = 0; j < maxColIndTemp; ++j){
				if (matrix[i][j] == target)
					return true;
				else if (matrix[i][j] > 0){
					maxColIndTemp = j;
					break;
				}
			}
		}

		auto maxRowIndTemp = maxRowInd;
		for (auto i = 0 ; i < maxRowIndTemp; ++i){
			for (auto j = 0; j < maxColInd; ++j){
				if (matrix[i][j] == target)
					return true;
				else if (matrix[i][j] > target){
					maxRowIndTemp = j;
					break;
				}
			}
		}
		return false;
        
    }
};
