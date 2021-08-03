// https://leetcode.com/problems/perfect-squares

#include <iostream>
#include <vector>

class Solution {
public:
    int numSquares(int n) {
		std::vector<int> vecSides;
		for (int i = 1; i*i <= n; ++i){
			vecSides.push_back(i);
		}

		std::vector<int> dp(n+1,0);
        dp[1] = 1 ;
		for (auto t = 2; t < n+1; ++t){
			auto minDp = t;
			for (auto s = 0 ;s < vecSides.size() && vecSides[s] * vecSides[s] <= t; ++s){
				minDp = std::min(dp[t-vecSides[s] * vecSides[s]],minDp);
			}
			dp[t] = minDp + 1;
		}

		return dp.back(); 
        
    }
};
