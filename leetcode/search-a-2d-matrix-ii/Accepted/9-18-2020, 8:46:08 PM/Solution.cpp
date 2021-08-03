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
		auto minRowInd = -1;
		for (auto i = 0; i < numRows; ++i){
			if (maxRowInd == numRows && matrix[i][0] > target){
				maxRowInd = i;
			}
			if (matrix[i][numCols-1] < target){
				minRowInd = i;
			}
		}
		auto maxColInd = numCols;
		auto minColInd = -1;
		for (auto j = 0; j < numCols; ++j){
			if (maxColInd == numCols && matrix[0][j] > target){
				maxColInd = j;
			}
			if (matrix[numRows-1][j] < target){
				minColInd = j;
			}
		}

		auto maxColIndTemp = maxColInd;

		for (auto i = minRowInd+1; i < maxRowInd; ++ i){
			for (auto j = minColInd+1; j < maxColIndTemp; ++j){
				if (matrix[i][j] == target)
					return true;
				else if (matrix[i][j] > target){
					maxColIndTemp = j;
					break;
				}
			}
		}

		return false;
        
    }
};
