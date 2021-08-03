// https://leetcode.com/problems/maximal-square

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		auto numRows = matrix.size();
		if (numRows == 0) return 0; 
		auto numCols = matrix[0].size();
		if (numCols == 0) return 0;

		std::vector<int> dp(numCols,0);
		int maxLen = 0;
		
		for (auto t = 0; t < numRows; ++t){
			if (t == 0){
				for (auto i = 0; i < numCols; ++i){
					dp[i] = matrix[0][i]-'0';
					maxLen = std::max(maxLen,dp[i]);
				}
			}
			else{
				auto prev = dp[0];
				dp[0] = matrix[t][0]-'0';
                maxLen = std::max(maxLen,dp[0]);
				for(auto i = 1; i < numCols; ++i){
					auto temp = dp[i];
					dp[i] = int((std::min(std::min(prev,dp[i-1]),dp[i])+1) * (matrix[t][i]-'0') );
					prev = temp;
					maxLen = int(std::max(maxLen,dp[i]));
				}
			}

		}
		return  maxLen * maxLen;

	}
};
