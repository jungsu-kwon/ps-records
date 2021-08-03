// https://leetcode.com/problems/perfect-squares

#include <iostream>
#include <vector>

class Solution {
public:
    int numSquares(int n) {
		std::vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
		for (auto t = 4; t < n+1; ++t){
			auto minDp = t;
			for (auto s = 1;s*s <= t; ++s){
				minDp = std::min(dp[t-(s*s)],minDp);
			}
			dp[t] = minDp + 1;
		}

		return dp.back(); 
    }
};



